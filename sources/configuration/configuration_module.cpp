#include "configuration_module.h"

namespace kraken
{
    void ConfigurationModule::registerCallback(ConfigurationCallback callback)
    {
        callbacks_holder_ += callback;
    }

    void ConfigurationModule::changeSection(ConfigurationHandler &configuration_handler, std::string new_section)
    {
        if (new_section != current_section_)
        {
            current_section_ = new_section;
            callbacks_holder_(configuration_handler);
        }
    }

    std::string ConfigurationModule::getCurrentSection()
    {
        return current_section_;
    }
}