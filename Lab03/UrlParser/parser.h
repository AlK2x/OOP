#pragma once
#include "stdafx.h"
#include <string>
#include <utility>
#include <algorithm>

enum Protocol
{
	HTTP,
	HTTPS,
	FTP
};

typedef struct ProtocolDefaultSettings
{
	std::string protocolAsString;
	Protocol protocol;
	int port;
} ProtocolSetting;

typedef struct UrlInfo
{
	Protocol protocol;
	std::string host;
	int port;
	std::string document;
} UrlSettings;

bool FindHostWithPort(std::string const& url, UrlSettings & urlInfo, size_t & searchFrom);
bool FindProtocol(std::string url, UrlSettings & urlSettings, size_t & searchFrom);

bool ParseUrl(std::string const& url, Protocol & protocol, int & port, std::string & host,
	std::string & document);
