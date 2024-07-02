#include "BeaconManager.h"

BeaconManager::BeaconManager() : _currentBeaconConfig(_beacon_config.end()) {
}


void BeaconManager::loadConfig(const std::list<Configuration::Beacon> &beacon_config) {
  _beacon_config       = beacon_config;
  _currentBeaconConfig = _beacon_config.begin();
}


std::list<Configuration::Beacon>::iterator BeaconManager::getCurrentBeaconConfig() const {
  return _currentBeaconConfig;
}


void BeaconManager::loadNextBeacon() {
  ++_currentBeaconConfig;
  if (_currentBeaconConfig == _beacon_config.end()) {
    _currentBeaconConfig = _beacon_config.begin();
  }
}
