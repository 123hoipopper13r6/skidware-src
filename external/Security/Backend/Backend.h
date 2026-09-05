#pragma once
#include <string>
#include <cstdint>

namespace Backend
{
	struct HttpResponse
	{
		int status = 0;
		std::string body;
	};

	namespace Utils
	{
		// Performs an HTTPS JSON request. method: "GET"/"POST". token is the
		// optional Bearer token. Returns status code + raw response body.
		HttpResponse HttpRequest(
			const std::wstring& method,
			const std::wstring& path,
			const std::string& body,
			const std::string& token = "");

		// Convenience wrappers.
		inline HttpResponse Get(const std::wstring& path, const std::string& token = "") { return HttpRequest(L"GET", path, "", token); }
		inline HttpResponse Post(const std::wstring& path, const std::string& body, const std::string& token = "") { return HttpRequest(L"POST", path, body, token); }
	}

	namespace Hwid
	{
		// Stable machine fingerprint (SHA-256 hex). Same across runs on one PC.
		std::string Get();
	}

	namespace Auth
	{
		struct Session
		{
			bool authenticated = false;
			std::string token;
			std::string email;
			std::string username;
			std::string hwid;
			std::string role;
		};

		// Returns the current session (persisted on disk).
		Session& Current();

		// Logs in with email + password, reports the HWID, persists the token.
		// Returns true on success. On HWID mismatch fills errorMessage.
		bool Login(const std::string& email, const std::string& password, std::string& errorMessage);

		// Logs in via Discord OAuth. Opens the default browser, waits for the
		// user to authorize, then polls the API for the session token.
		// Blocks until done (run in its own thread). Returns true on success.
		bool LoginWithDiscord(std::string& errorMessage);

		// Validates the saved token against the server and re-reports HWID.
		// Returns true if the session is still valid.
		bool Validate();

		void Logout();
	}
}
