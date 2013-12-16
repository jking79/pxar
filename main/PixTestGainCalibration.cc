#include <iostream>
#include "PixTestGainCalibration.hh"

using namespace std;

ClassImp(PixTestGainCalibration)

//----------------------------------------------------------
PixTestGainCalibration::PixTestGainCalibration(TBInterface *tb, std::string name, PixTestParameters *tp): PixTest(tb, name, tp) {
  cout << "PixTestGainCalibration ctor(TBInterface *, string)" << endl;
}

//----------------------------------------------------------
PixTestGainCalibration::PixTestGainCalibration(): PixTest() {
  cout << "PixTestGainCalibration ctor()" << endl;
}

//----------------------------------------------------------
PixTestGainCalibration::~PixTestGainCalibration() {
  cout << "PixTestGainCalibration dtor()" << endl;
}

// ----------------------------------------------------------------------
bool PixTestGainCalibration::setParameter(string parName, string sval) {
  bool found(false);
  for (map<string,string>::iterator imap = fParameters.begin(); imap != fParameters.end(); ++imap) {
    if (0 == imap->first.compare(parName)) {
      found = true; 
      break;
    }
  }
  if (found) {
    fParameters[parName] = sval;
  }

  return found;
}

// ----------------------------------------------------------------------
void PixTestGainCalibration::doTest() {
  cout << "PixTestGainCalibration::doTest()" << endl;
}