#include "domain.hpp"

namespace wot
{
domain::domain()
{
}

void domain::add_hostname(const std::string& hostname)
{
    m_hostnames.push_back(hostname);
}

void domain::set_location(const std::string& location)
{
    m_location = location;
}

void domain::set_404(const std::string& file_404)
{
    m_404 = file_404;
}

void domain::add_path(const wot::path& path)
{
    m_paths[path.request] = path;
}

bool domain::is_hostname(const std::string& hostname)
{
    return std::find(m_hostnames.begin(), m_hostnames.end(), hostname) != m_hostnames.end();
}

std::string domain::get_location()
{
    return m_location;
}

std::string domain::get_404()
{
    return m_404;
}

wot::path domain::get_path(const std::string& path)
{
    return m_paths[path];
}

}