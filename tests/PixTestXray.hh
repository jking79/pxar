#ifndef PIXTESTXRAY_H
#define PIXTESTXRAY_H

#include "PixTest.hh"
#include "PHCalibration.hh"

#include <TProfile2D.h>


class DLLEXPORT PixTestXray: public PixTest {
public:
  PixTestXray(PixSetup *, std::string);
  PixTestXray();
  virtual ~PixTestXray();
  virtual bool setParameter(std::string parName, std::string sval); 
  void init(); 
  void setToolTips();
  void bookHist(std::string); 

  void runCommand(std::string command); 
  void doPhRun(); 
  void doRateScan();
  void doTest();
 
  bool setTrgFrequency(uint8_t TrgTkDel);
  void finalCleanup();
  void pgToDefault(std::vector<std::pair<std::string, uint8_t> > pg_setup);

  void readData();
  void analyzeData();

  double meanHit(TH2D*); 
  double noiseLevel(TH2D*); 
  int   countHitsAndMaskPixels(TH2D*, double noiseLevel, int iroc); 

  void processData(uint16_t numevents = 1000);

private:

  std::string   fParSource;
  int           fParTriggerFrequency;
  int           fParRunSeconds; 
  int           fParStepSeconds; 
  int           fParVthrCompMin, fParVthrCompMax; 
  bool          fParFillTree;
  bool	        fParDelayTBM;
  uint16_t      fParNtrig; 
  int           fParVcal; 

  bool          fPhCalOK;
  PHCalibration fPhCal;

  bool    fDaq_loop;
  
  int     fVthrComp;

  std::vector<std::pair<std::string, uint8_t> > fPg_setup;

  // -- rateScan
  std::vector<TH1D*> fHits, fMpix;
  std::vector<TH2D*> fHitMap;

  // -- PhRun
  std::vector<TH1D*> fQ;
  std::vector<TProfile2D*> fQmap;

  std::vector<TH1D*> fPH;
  std::vector<TProfile2D*> fPHmap;
  std::vector<TH2D*> fHmap;

  std::vector<TH1D*> fTriggers;
  
  ClassDef(PixTestXray, 1)

};
#endif
