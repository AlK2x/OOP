#include "stdafx.h"
#include "../UrlParser/parser.h"

using namespace std;

struct PrepareVariablesForUrlPartsStoring
{
	Protocol protocol;
	int port;
	string host;
	string document;
};

BOOST_FIXTURE_TEST_SUITE(ParseUrlTest, PrepareVariablesForUrlPartsStoring)

BOOST_AUTO_TEST_CASE(TestFindProtocol)
{
	string url("http://www.valid.url");
	BOOST_CHECK(ParseUrl(url, protocol, port, host, document));
	BOOST_CHECK_EQUAL(protocol, HTTP);
	BOOST_CHECK_EQUAL(host, "www.valid.url");

	string url1("ftp://valid.ftp");
	BOOST_CHECK(ParseUrl(url1, protocol, port, host, document));
	BOOST_CHECK_EQUAL(protocol, FTP);
	BOOST_CHECK_EQUAL(host, "valid.ftp");

	string url2("https://www.validSecure.url");
	BOOST_CHECK(ParseUrl(url2, protocol, port, host, document));
	BOOST_CHECK_EQUAL(protocol, HTTPS);
	BOOST_CHECK_EQUAL(host, "www.validSecure.url");

	string url3("not://notvalidUrl");
	BOOST_CHECK(!ParseUrl(url3, protocol, port, host, document));

}

BOOST_AUTO_TEST_SUITE_END()
