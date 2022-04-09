#ifndef __RESOURCEMANAGER_HPP__
#define __RESOURCEMANAGER_HPP__

#include <thread>
#include <atomic>
#include <condition_variable>

class ResourceManager{
public:
    static ResourceManager* getInstance();
    std::mutex screenMux;
private:
    static ResourceManager* uniqueInstance;
    ResourceManager() = default;
    ResourceManager(const ResourceManager& rhs) = default;
    ~ResourceManager();
};
ResourceManager* ResourceManager::uniqueInstance = nullptr;
ResourceManager::~ResourceManager(){
    if(uniqueInstance != nullptr){
            delete uniqueInstance;
        }
}
ResourceManager* ResourceManager::getInstance(){
    if(uniqueInstance == nullptr){
            uniqueInstance = new ResourceManager();
        }
    return uniqueInstance;
}
#endif