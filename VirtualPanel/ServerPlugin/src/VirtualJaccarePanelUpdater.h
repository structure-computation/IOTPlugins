#ifndef VirtualJaccarePanelUpdater_H
#define VirtualJaccarePanelUpdater_H

#include <Soca/Updater.h>
class SodaClient;
//class QDataStream;

/**
*/
class VirtualJaccarePanelUpdater : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "JaccarePanelItem"; }
    
public:
    SodaClient *sc;
    bool direct_run( MP mp );
    bool push_tracker( MP mp );
};

#endif // VirtualJaccarePanelUpdater_H
