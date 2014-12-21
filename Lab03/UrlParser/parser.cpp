#include "stdafx.h"
#include "parser.h"

using namespace std;

static const ProtocolSetting supportedProtocolsInfo[] = {
	{ "http", HTTP, 80 },
	{ "https", HTTPS, 443 },
	{ "ftp", FTP, 21 }
};

bool ParseUrl(std::string const& url, Protocol & protocol, int & port, std::string & host,
	std::string & document)
{
	size_t searchFrom = 0;
	bool parseResult;
	UrlSettings urlInfo;
	parseResult = FindProtocol(url, urlInfo, searchFrom);
	if (!parseResult)
	{
		return false;
	}
	parseResult = FindHostWithPort(url, urlInfo, searchFrom);
	if (!parseResult)
	{
		return false;
	}

	protocol = urlInfo.protocol;
	port = urlInfo.port;
	host = urlInfo.host;
	document = urlInfo.document;

	return parseResult;
}

bool FindProtocol(string url, UrlSettings & urlSettings, size_t & searchFrom)
{
	transform(url.begin(), url.end(), url.begin(), ::tolower);

	bool findProtocolSuccess = false;
	string protocolSeparator("://");
	int separatorPosition = url.find(protocolSeparator);

	for (auto supportedProtocol : supportedProtocolsInfo)
	{
		int compareResult = url.compare(0, separatorPosition, supportedProtocol.protocolAsString);
		if (compareResult == 0)
		{
			urlSettings.protocol = supportedProtocol.protocol;
			findProtocolSuccess = true;
			searchFrom = separatorPosition + protocolSeparator.size();
			break;
		}
	}

	return findProtocolSuccess;
}

bool FindHostWithPort(std::string const& url, UrlSettings & urlInfo, size_t & searchFrom)
{
	bool findHostSuccess = true;
	int portSeparatorPosition = url.find(":", searchFrom);
	int documentSeparatorPosition = url.find("/", searchFrom);
	if (portSeparatorPosition != string::npos && portSeparatorPosition < documentSeparatorPosition)
	{
		urlInfo.host = url.substr(searchFrom, searchFrom + portSeparatorPosition);
	}
	else if (documentSeparatorPosition != string::npos)
	{
		urlInfo.host = url.substr(searchFrom, searchFrom + documentSeparatorPosition);
	}
	else if (url.size() > searchFrom)
	{
		urlInfo.host = url.substr(searchFrom);
	}
	else
	{
		findHostSuccess = false;
	}

	return findHostSuccess;
}