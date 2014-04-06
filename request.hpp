#ifndef _SAMMY_REQUEST_
#define _SAMMY_REQUEST_

#include <string>
#include <vector>
#include <memory>
#include <map>

#include "utils/utils.hpp"

namespace sammy
{
class request
{
public:
    request(const std::string& request);

    std::string get_host() const;
    std::string get_path() const;
    std::string get_method() const;
    std::string get_post_data() const;
    std::string get_referer() const;

    bool errors() const;
    std::string error_text() const;

private:
    void parse_header();
    void parse_host(const std::string& host_data);
    void parse_cookies(const std::string& cookie_data);
    void parse_post_data();
    void parse_referer(const std::string& referer_data);

    std::string m_method;
    std::string m_path;
    std::string m_host;
    std::string m_post_data;
    std::string m_referer;
    std::map<std::string, std::string> m_cookies;

    int m_error;
    std::string m_error_text;

    std::vector<std::string> m_request_lines;
};
}

#endif
