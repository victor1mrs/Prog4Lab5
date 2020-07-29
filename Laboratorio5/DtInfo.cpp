/*
 * DtInfo.cpp
 *
 *  Created on: 3 jun. 2020
 *      Author: Santi
 */

#include "DtInfo.h"

DtInfo::DtInfo(DtFecha fi, DtFecha ff, DtHora hi, DtHora hf){
    fIni = fi;
    fFin = ff;
    hIni= hi;
    hFin = hf;
};
DtFecha DtInfo::getfIni(){
    return fIni;
};
DtFecha DtInfo::getfFin(){
    return fFin;
};
DtHora DtInfo::gethIni(){
    return hIni;
};
DtHora DtInfo::gethFin(){
    return hFin;
};
DtInfo::~DtInfo(){

};
void DtInfo::setFechaYHoraFinales(DtFecha f, DtHora h){
    fFin = f;
    hFin = h;
};
float DtInfo::calculoTiempoDtInfo(){

    int segundosFin = this->hFin.getsegundo();
    int segundosIni = this->hIni.getsegundo();
    int segundosRes;
    if (segundosIni > segundosFin) segundosRes = 60 - segundosIni + segundosFin;
    else segundosRes = segundosFin - segundosIni;

    int minutosFin = this->hFin.getminuto();
    int minutosIni = this->hIni.getminuto();
    int minutosRes;
    if (minutosIni > minutosFin && segundosIni > segundosFin) minutosRes = 60 - minutosIni + minutosFin -1;
        else if (minutosIni > minutosFin && segundosIni < segundosFin) minutosRes = 60 - minutosIni + minutosFin;
            else if (segundosIni > segundosFin) minutosRes = minutosFin - minutosIni - 1;
                     else minutosRes = minutosFin - minutosIni;
                minutosRes = 60*(minutosRes);

    int horasFin = this->hFin.gethora();
    int horasIni = this->hIni.gethora();
    int horasRes;
    if (horasIni > horasFin && minutosIni > minutosFin) horasRes = 24 - horasIni + horasFin -1;
        else if (horasIni > horasFin && minutosIni < minutosFin) horasRes = 24 - horasIni + horasFin;
            else if (minutosIni > minutosFin) horasRes = horasFin - horasIni - 1;
                     else horasRes = horasFin - horasIni;
            horasRes = 60*60*(horasRes);

    float tiempoRes = (segundosRes + minutosRes + horasRes);

    return tiempoRes;
}
