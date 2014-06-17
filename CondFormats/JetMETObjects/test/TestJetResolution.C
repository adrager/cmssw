void TestJetResolution()
{
double rawPt=100;
double rawEta=1;
double rawPhi=0;
double rawE=9.8; 
double JPTE=200;
int NPU=20;
  gROOT->ProcessLine("#include <vector>");
  gSystem->Load("libFWCoreFWLite.so");
  AutoLibraryLoader::enable();
  ////////////// Construct the JetCorrectorParameters objects ///////////////////////

  string L1Tag    = "../data/JetResolutionInput.txt"; 
  JetCorrectorParameters *L1Par    = new JetCorrectorParameters(L1Tag);
  cout<<"L1Par isValid:"<<L1Par->isValid()<<endl;
  cout<<"L1Par size:"<<L1Par->size()<<endl;
//  cout<<"L1Par printScreen:"<<L1Par->printScreen()<<endl;
  ////////////// Construct a FactorizedJetCorrector object //////////////////////
  SimpleJetCorrector *JetUncertainty = new SimpleJetCorrector(*L1Par);
//  JetUncertainty->setJetEta(0.4);
  ////////////// Loop over jets //////////////////////
  std::vector<float> fx, fY;
  fx.push_back(0.04);
  fY.push_back(100);
  fY.push_back(10);
  SimpleJetResolution *resolution =  new SimpleJetResolution(*L1Par);
  cout<<"SimpleJetResolution->resolution(): "<<resolution->resolution(fx,fY)<<endl;  
//  cout<<"Correction applied to JPT jet after L1Offset = "<<vcor[0]<<endl;
//  cout<<"Correction applied to JPT jet after L1JPTOffset = "<<vcor[1]<<endl;
}
