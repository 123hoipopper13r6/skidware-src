#pragma once
#include "../Includes.hpp"
namespace SDK
{
	inline bool Scan()
	{
		PushNotification("Scanning Roblox...");
		Logging::Log(Logging::LogType::INFO, "Scanning... Roblox Base -> 0x%llX", SDK::RobloxBase);
		try
		{
			auto dm = SDK::FetchDatamodel();
			if (!dm.Address)
			{
				Logging::Log(Logging::LogType::ERR, "Scan failed - DataModel not ready yet");
				return false;
			}
			Globals::DataModel = dm;
			Globals::VisualEngine = SDK::FetchVisualEngine();

			Globals::Players = (SDK::Players)Globals::DataModel.FindFirstChildOfClass("Players");
			Globals::Workspace = Globals::DataModel.FindFirstChildOfClass("Workspace");
			Globals::LocalPlayer = Globals::Players.LocalPlayer();
			Globals::MouseService = (SDK::MouseService)Globals::DataModel.FindFirstChildOfClass("MouseService");
			Globals::Lighting = Globals::DataModel.FindFirstChildOfClass("Lighting");
			Globals::GameID = Globals::DataModel.GameID();

			Logging::Log(Logging::LogType::INFO, "Scan finished. Datamodel -> 0x%llX", Globals::DataModel.Address);
			Logging::Log(Logging::LogType::INFO, "LocalPlayer -> 0x%llX", Globals::LocalPlayer.Address);
			Logging::Log(Logging::LogType::INFO, "MouseService -> 0x%llX", Globals::MouseService.Address);
			Logging::Log(Logging::LogType::INFO, "Players -> 0x%llX", Globals::Players.Address);
			Logging::Log(Logging::LogType::INFO, "Workspace -> 0x%llX", Globals::Workspace.Address);
			Logging::Log(Logging::LogType::INFO, "VisualEngine -> 0x%llX", Globals::VisualEngine.Address);
			Logging::Log(Logging::LogType::INFO, "Lighting -> 0x%llX", Globals::Lighting.Address);
			Logging::Log(Logging::LogType::INFO, "GameID -> %i", Globals::GameID);
		}
		catch (const std::exception& e)
		{
			Logging::Log(Logging::LogType::ERR, "Scan exception: %s", e.what());
			return false;
		}
		catch (...)
		{
			Logging::Log(Logging::LogType::ERR, "Scan exception (unknown)");
			return false;
		}
		PushNotification("Rescan complete");
		return true;
	}
	inline void InitializeAutoRescan()
	{
		while (true)
		{
			SDK::DataModel currentDm = SDK::FetchDatamodel();
			if (currentDm.Address != 0)
			{
				bool changed = Globals::DataModel.Address != currentDm.Address;
				bool missing = Globals::Players.Address == 0 || Globals::Workspace.Address == 0;
				bool gameChanged = Globals::GameID != currentDm.GameID();
				if (changed || missing || gameChanged)
				{
					if (changed)
						Logging::Log(Logging::LogType::INFO, "Scene change detected, rescanning.");
					else if (gameChanged)
						Logging::Log(Logging::LogType::INFO, "GameID changed, rescanning.");
					else
						Logging::Log(Logging::LogType::INFO, "Children missing, retrying scan.");
					if (SDK::Scan())
						ConfigManager::CheckGameIdChange();
				}
			}
			std::this_thread::sleep_for(std::chrono::seconds(3));
		}
	}
	inline void SDKCacheUpdate()
	{
		while (true)
		{
			try
			{
				SDK::VisualEngineCache::ViewMatrix = Globals::VisualEngine.ViewMatrix();
			}
			catch (...)
			{
				Logging::Log(Logging::LogType::ERR, "Caught crash at SDKCacheUpdate");
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}
	}
	inline bool Initialize()
	{
		// offsets come from the skidware-dumper output (Roblox/Offsets.hpp);
		// the remote OffsetsUpdater + version gate are disconnected - re-dump
		// after a Roblox update instead
		SDK::Scan();
		ConfigManager::CurrentGameId = Globals::GameID;
		ConfigManager::PreviousGameId = Globals::GameID;
		ConfigManager::InGame = Globals::GameID != 0;
		if (Globals::GameID != 0) {
			ConfigManager::LoadConfig(Globals::GameID);
		}
		std::thread(SDK::InitializeAutoRescan).detach();
		std::thread(SDK::SDKCacheUpdate).detach();
		return true;
	}
}