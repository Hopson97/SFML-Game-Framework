#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED

#include <unordered_map>
#include <string>

template<typename Resource>
class ResourceManager
{
    using CrString = const std::string&;

    public:
        ResourceManager (CrString folder, CrString extention)
        :   m_folder    ("res/" + folder + "/")
        ,   m_extention ("." + extention)
        { }

        const Resource& get(CrString name)
        {
            if (!exists(name))
            {
                add(name);
            }

            return m_resources.at(name);
        }

        bool exists(CrString name) const
        {
            return m_resources.find(name) != m_resources.end();
        }

        void add(CrString name)
        {
            Resource r;

            //if the resource fails to load, then it adds a default "fail" resource
            if(!r.loadFromFile(getFullname(name)))
            {
                Resource fail;
                fail.loadFromFile(m_folder + "_fail_" + m_extention);
                m_resources.insert(std::make_pair(name, fail));
            }
            else
            {
                m_resources.insert(std::make_pair(name, r));
            }
        }

    private:
        std::string getFullname(CrString name)
        {
            return m_folder + name + m_extention;
        }

        const std::string m_folder;
        const std::string m_extention;

        std::unordered_map<std::string, Resource> m_resources;
};

#endif // RESOURCEMANAGER_H_INCLUDED
