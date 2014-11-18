#ifndef JaccarePanelAnalytics_H
#define JaccarePanelAnalytics_H

#include <Soca/Updater.h>
class SodaClient;
//class QDataStream;

/**
*/
class JaccarePanelAnalytics : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "JaccarePanelItem"; }
    
public:
    SodaClient *sc;
    bool direct_run( MP mp );
};

#endif // JaccarePanelAnalytics_H
