#ifndef JACCAREPANELMANAGERUPDATER_H
#define JACCAREPANELMANAGERUPDATER_H

#include <Soca/Updater.h>
class SodaClient;
//class QDataStream;

/**
*/
class JaccarePanelUpdater : public Updater {
protected:
    bool run( MP mp );
    virtual QString type() const { return "JaccarePanelManagerItem"; }
    
public:
    SodaClient *sc;
    bool direct_run( MP mp );
};

#endif // JACCAREPANELMANAGERUPDATER_H
