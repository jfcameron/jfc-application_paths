// © Joseph Cameron - All Rights Reserved

#ifndef JFC_APPLICATION_PATHS_H
#define JFC_APPLICATION_PATHS_H

#include <filesystem>
#include <string>

///
/// \brief: libray for creating and accessing application specific 
/// directories to read & write e.g: config files, logs, data...
/// the POSIX implementation follows freedesktop format for user directories
/// https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html#referencing
/// the windows implementation creates a subdirectory with your applciations name in the current user's
/// appdata directory
/// \todo: consider shared directories e.g: /var/log/appname, etc.
/// \todo: consider access to bundles, mac app, android
namespace jfc
{
    class application_paths final
    {
    public:
        /// \brief ~/.conf/appname [on linux]
        const std::filesystem::path &config_dir() const;

        /// \brief ~/.cache/appname [on linux]
        const std::filesystem::path &cache_dir() const;

        /// \brief ~/.local/share/appname [on linux]
        const std::filesystem::path &data_dir() const;

        application_paths(const std::filesystem::path &aApplicationName);
        
    private:
        std::filesystem::path m_config_dir;
        std::filesystem::path m_cache_dir; 
        std::filesystem::path m_data_dir; 
    };
}
#endif

#ifdef JFC_APPLICATION_PATHS_IMPLEMENTATION
namespace jfc
{
    namespace fs = std::filesystem;

    application_paths::application_paths(const std::filesystem::path &aApplicationName)
    {
#if defined WIN32
        static const std::string appdata(std::getenv("appdata"));

        m_config_dir = appdata / aApplicationName / "config"; 
        m_cache_dir  = appdata / aApplicationName / "cache"; 
        m_data_dir   = appdata / aApplicationName / "data"; 
#else
        static const std::filesystem::path home(std::getenv("HOME"));

        m_config_dir = home / ".config"     / aApplicationName; 
        m_cache_dir  = home / ".cache"      / aApplicationName; 
        m_data_dir   = home / ".localshare" / aApplicationName; 
#endif
    };

    const std::filesystem::path &application_paths::config_dir() const 
    { 
        if (!fs::exists(m_config_dir)) if (!fs::create_directories(m_config_dir))
            throw std::runtime_error("could not create directory: " + m_config_dir.string());

        return m_config_dir; 
    }
    
    const std::filesystem::path &application_paths::cache_dir() const 
    { 
        if (!fs::exists(m_cache_dir)) if (!fs::create_directories(m_cache_dir))
            throw std::runtime_error("could not create directory: " + m_cache_dir.string());

        return m_cache_dir; 
    }
    
    const std::filesystem::path &application_paths::data_dir() const 
    { 
        if (!fs::exists(m_data_dir)) if (!fs::create_directories(m_data_dir)) 
            throw std::runtime_error("could not create directory: " + m_data_dir.string());

        return m_data_dir; 
    }
}
#endif

