#ifndef _SAMMY_DOMAIN_
#define _SAMMY_DOMAIN_

#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include "utils/utils.hpp"

namespace sammy
{
enum class path_type
{
    plain = 1,
    binary = 2,
    python = 3,
    unknown = 4
};

enum class method_type
{
    get = 1,
    post = 2,
    unknown = 3
};

struct path
{
    std::string request;
    sammy::path_type type;
    sammy::method_type method;
    std::string file;

    path():
        request(""),
        type(sammy::path_type::unknown),
        method(sammy::method_type::unknown),
        file("")
    {
    };
    
    path(const std::string& r, sammy::path_type t, sammy::method_type m, const std::string& f):
        request(r),
        type(t),
        method(m),
        file(f)
    {
    };
    
    path(const std::string& r, const std::string& t, const std::string& m, const std::string& f):
        request(r),
        file(f)
    {
        method = sammy::method_type::unknown;
        if(m == "get")
        {
            method = sammy::method_type::get;
        }
        else if(m == "post")
        {
            method = sammy::method_type::post;
        }

        type = sammy::path_type::unknown;
        if(t == "plain")
        {
            type = sammy::path_type::plain;
        }
        else if(t == "python")
        {
            type = sammy::path_type::python;
        }
        else if (t == "binary")
        {
            type = sammy::path_type::binary;
        }
    }

    bool operator==(const path& b)
    {
        return this->type == b.type
            && this->method == b.method
            && this->request == b.request
            && this->file == b.file;
    }
};

class domain
{
public:
    domain();

    void add_hostname(const std::string& hostname);
    void add_blacklist(const std::string& blacklist);
    void set_location(const std::string& location);
    void set_404(const std::string& file_404);
    void add_path(const sammy::path& path);

    bool is_hostname(const std::string& hostname);
    bool is_blacklisted(const std::string& blacklist);
    std::string get_location();
    std::string get_404();
    sammy::path get_path(sammy::method_type method, const std::string& path);
    sammy::path find_wildcard_path(sammy::method_type method, const std::string& path);
    std::vector<std::string> get_hostnames();

private:
    std::vector<std::string> m_hostnames;
    std::vector<std::string> m_blacklist;
    std::string m_location;
    std::string m_404;
    std::map<sammy::method_type, std::map<std::string, sammy::path>> m_paths;
};
}

#endif
