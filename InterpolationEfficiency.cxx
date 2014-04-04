#include <iomanip>
#include <fstream>
#include <vector>
#include <map>

//----                low   dR                 hi    dR
std::pair< std::pair <int, float> , std::pair <int, float> > GetCloserMass(float mass, std::vector<float> &vTemplateMasses) {
 
 float Dx_lo;
 float Dx_hi;
 
 int iTemplate_lo = -1;
 int iTemplate_hi = -1;
//   std::cout << " vTemplateMasses.size() = " << vTemplateMasses.size() << std::endl;
 if (vTemplateMasses.size() != 1) {
  for (int iMass = 0; iMass < (vTemplateMasses.size()-1); iMass++) {
   float tempDx_lo;
   float tempDx_hi;
   
   tempDx_lo = mass - vTemplateMasses.at(iMass);
   tempDx_hi = vTemplateMasses.at(iMass+1) - mass;
   
//    std::cout << " iMass = " << iMass << " :: tempDx_lo = " << tempDx_lo << " ; tempDx_hi = " << tempDx_hi << std::endl;
   if (tempDx_lo >= 0 && tempDx_hi > 0) { //----> it's between A -- mass --- B
    iTemplate_lo = iMass;
    Dx_lo = fabs(tempDx_lo);
    iTemplate_hi = iMass+1;
    Dx_hi = fabs(tempDx_hi);
   break;
   }
  }
 }
 
 std::pair <int, float> lo_pair (iTemplate_lo, Dx_lo);
 std::pair <int, float> hi_pair (iTemplate_hi, Dx_hi);
 
 return std::pair< std::pair <int, float> , std::pair <int, float> > (lo_pair, hi_pair) ;
}


void  copyV2Vf (float V[], std::vector<float> &vV, int n) {
 for (int i=0; i< n; i++) {
//   std::cout << " float : i+1 = " << i+1 << " : " << n << " -> " << V[i] << std::endl;
  vV.push_back(V[i]);
 }
}

void  copyV2Vs (std::string V[], std::vector<std::string> &vV, int n) { ///----> per qualche arcano motivo non funziona!
 for (int i=0; i< n; i++) {
//   std::cout << " string: i+1 = " << i+1 << " : " << n << " -> " << V[i] << std::endl;
  vV.push_back(V[i]);
 }
}


void InterpolationEfficiency(std::string templateDC, std::string lumi = "19.47", std::string tag = "of_2j_shape", int sqrts = 8, int lowMass = 0 ){
 
 ///===========================================================================
  
 std::cout << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 std::cout << std::endl;
 
 std::cout << "templateDC  = " << templateDC  << std::endl;
 
 
 
 if (sqrts == 8) {
  if (lowMass == 0) { //---- only low masses: VH
   gROOT->ProcessLine ("float TemplateMasses[] =           { 110 , 115 , 120 , 125 , 130 , 135 , 140 , 145 , 150 , 155 , 160 , 170 , 180 , 190 , 200 , 250 , 300};");
   gROOT->ProcessLine ("std::string NameTemplateMasses[] = {\"110\",\"115\",\"120\",\"125\",\"130\",\"135\",\"140\",\"145\",\"150\",\"155\",\"160\",\"170\",\"180\",\"190\",\"200\",\"250\",\"300\"};");
  }
  else {
   gROOT->ProcessLine ("float TemplateMasses[] =           { 110 , 115 , 120 , 125 , 130 , 135 , 140 , 145 , 150 , 155 , 160 , 170 , 180 , 190 , 200 , 250 , 300 , 350 , 400 , 450 , 500 , 550 , 600};");
   gROOT->ProcessLine ("std::string NameTemplateMasses[] = {\"110\",\"115\",\"120\",\"125\",\"130\",\"135\",\"140\",\"145\",\"150\",\"155\",\"160\",\"170\",\"180\",\"190\",\"200\",\"250\",\"300\",\"350\",\"400\",\"450\",\"500\",\"550\",\"600\"};");
  }
 }
 else {
  if (lowMass == 0) { //---- only low masses: VH
//    gROOT->ProcessLine ("float TemplateMasses[] =           { 110 , 115 , 120 , 125 , 130 , 135 , 140 ,       150 ,       160 , 170 , 180 , 190};");
//    gROOT->ProcessLine ("std::string NameTemplateMasses[] = {\"110\",\"115\",\"120\",\"125\",\"130\",\"135\",\"140\",\"150\",\"160\",\"170\",\"180\",\"190\"};");   
   gROOT->ProcessLine ("float TemplateMasses[] =           {120 , 125 , 130 , 135 , 140 ,       150 ,       160 , 170 , 180 , 190};");
   gROOT->ProcessLine ("std::string NameTemplateMasses[] = {\"120\",\"125\",\"130\",\"135\",\"140\",\"150\",\"160\",\"170\",\"180\",\"190\"};");   
  }
  else {
   gROOT->ProcessLine ("float TemplateMasses[] =           { 110 , 115 , 120 , 125 , 130 , 135 , 140 ,       150 ,       160 , 170 , 180 , 190 , 200 , 250 , 300 , 350 , 400 , 450 , 500 , 550 , 600};");
   gROOT->ProcessLine ("std::string NameTemplateMasses[] = {\"110\",\"115\",\"120\",\"125\",\"130\",\"135\",\"140\",\"150\",\"160\",\"170\",\"180\",\"190\",\"200\",\"250\",\"300\",\"350\",\"400\",\"450\",\"500\",\"550\",\"600\"};");
  }
 }
 
 
//  float TemplateMasses[] =           { 110 , 115 , 120 , 125 , 130 , 140 , 150 , 160 , 170 , 180 , 190 , 200 , 250 , 300 , 350 , 400 , 450 , 500 , 550 , 600};
 std::vector<float> vTemplateMasses;
 copyV2Vf (TemplateMasses, vTemplateMasses, sizeof(TemplateMasses)/sizeof(float));

//  std::string NameTemplateMasses[] = {"110","115","120","125","130","140","150","160","170","180","190","200","250","300","350","400","450","500","550","600"};
//  std::cout << " NameTemplateMasses[0] = " << NameTemplateMasses[0] << std::endl;
//  std::cout << " NameTemplateMasses[1] = " << NameTemplateMasses[1] << std::endl;
//  std::cout << " NameTemplateMasses[2] = " << NameTemplateMasses[2] << std::endl;
//  std::cout << " NameTemplateMasses[3] = " << NameTemplateMasses[3] << std::endl;
//  std::vector< std::string > vNameTemplateMasses = {"110","115","120","125","130","140","150","160","170","180","190","200","250","300","350","400","450","500","550","600"};
//  above valid only in c++11
 std::vector< std::string > vNameTemplateMasses;
 for (int i=0; i<sizeof(NameTemplateMasses)/sizeof(std::string); i++) {
  vNameTemplateMasses.push_back(NameTemplateMasses[i]);
 }
//  std::cout << "  sizeof(NameTemplateMasses)/sizeof(std::string) = " <<  sizeof(NameTemplateMasses) << " / " << sizeof(std::string) << std::endl;
//  copyV2Vs (NameTemplateMasses, vNameTemplateMasses, sizeof(NameTemplateMasses)/sizeof(std::string));
//  std::vector< std::string > vNameTemplateMasses (NameTemplateMasses, NameTemplateMasses + sizeof(NameTemplateMasses) / sizeof(std::string) );
 
 
//  if (sqrts == 8) {
//   gROOT->ProcessLine ("float AllMasses[] = {111,112,113,114,    116,117,118,119,    121,122,123,124,    126,127,128,129,    131,132,133,134,136,137,138,139,    141,142,143,144,145,146,147,148,149,    151,152,153,154,155,156,157,158,159,    162,164,     166,168,    172,174,    176,178,    182,184,    186,188,    192,194,    196,198};");
//  }
//  else {
//   gROOT->ProcessLine ();
//  }
 
 
 
//  if (lowMass == 0)  { //---- only low masses: VH  
//  }
//  else {
//   gROOT->ProcessLine ("float AllMasses[] = {111,112,113,114,    116,117,118,119,    121,122,123,124,    126,127,128,129,    131,132,133,134,136,137,138,139,    141,142,143,144,145,146,147,148,149,    151,152,153,154,155,156,157,158,159,    162,164,     166,168,    172,174,    176,178,    182,184,    186,188,    192,194,    196,198};");
//  }
  

  float AllMasses[] = {111,112,113,114,    116,117,118,119,    121,122,123,124, 125.1,125.2,125.3,125.4,125.5,125.6,125.7,125.8,125.9,   126,127,128,129,    131,132,133,134,136,137,138,139,    141,142,143,144,145,146,147,148,149,    151,152,153,154,155,156,157,158,159,    162,164,     166,168,    172,174,    176,178,    182,184,    186,188,    192,194,    196,198};
  
//  float AllMasses[] = {111,112,113,114,    116,117,118,119,    121,122,123,124,    126,127,128,129,    131,132,133,134,136,137,138,139,    141,142,143,144,145,146,147,148,149,    151,152,153,154,155,156,157,158,159,    162,164,     166,168,    172,174,    176,178,    182,184,    186,188,    192,194,    196,198};
//  float AllMasses[] = {125.1,125.2,125.3,125.4,125.5,125.6,125.7,125.8,125.9};
 std::vector<float> vAllMasses;
 copyV2Vf (AllMasses, vAllMasses, sizeof(AllMasses)/sizeof(float));
//  std::vector<float> vAllMasses (AllMasses, AllMasses + sizeof(AllMasses) / sizeof(float) );

 std::string NameAllMasses[] = {"111","112","113","114","116","117","118","119","121","122","123","124","125.1","125.2","125.3","125.4","125.5","125.6","125.7","125.8","125.9","126","127","128","129","131","132","133","134","136","137","138","139","141","142","143","144","145","146","147","148","149","151","152","153","154","155","156","157","158","159","162","164","166","168","172","174","176","178","182","184","186","188","192","194","196","198"};
//  std::string NameAllMasses[] = {"125.1","125.2","125.3","125.4","125.5","125.6","125.7","125.8","125.9"};
//  std::string NameAllMasses[] = {"111","112","113","114","116","117","118","119","121","122","123","124","126","127","128","129","131","132","133","134","136","137","138","139","141","142","143","144","145","146","147","148","149","151","152","153","154","155","156","157","158","159","162","164","166","168","172","174","176","178","182","184","186","188","192","194","196","198"};
 std::vector< std::string > vNameAllMasses;
 for (int i=0; i<sizeof(NameAllMasses)/sizeof(std::string); i++) {
  vNameAllMasses.push_back(NameAllMasses[i]);
 }
//  copyV2Vs (NameAllMasses, vNameAllMasses, sizeof(NameAllMasses)/sizeof(std::string));
//  std::vector< std::string > vNameAllMasses (NameAllMasses, NameAllMasses + sizeof(NameAllMasses) / sizeof(std::string) );
 
 
 std::string SamplesToChange[] = {"ggH","qqH","WH","ZH","VH"};
 std::vector< std::string > vSamplesToChange;
 for (int i=0; i<sizeof(SamplesToChange)/sizeof(std::string); i++) {
  vSamplesToChange.push_back(SamplesToChange[i]);
 }
 
//  copyV2Vs (NameAllMasses, vNameAllMasses, sizeof(SamplesToChange)/sizeof(std::string));
//  std::vector< std::string > vSamplesToChange (SamplesToChange, SamplesToChange + sizeof(SamplesToChange) / sizeof(std::string) );
 
//  std::string xsecBrSamplesToChange[] = {"xs_br_h_ecm8tev_ggH.txt","xs_br_h_ecm8tev_qqH.txt","xs_br_h_ecm8tev_WH.txt","xs_br_h_ecm8tev_ZH.txt"};
//  std::vector< std::string > vxsecBrSamplesToChange;
//  for (int i=0; i<sizeof(xsecBrSamplesToChange)/sizeof(std::string); i++) {
//   vxsecBrSamplesToChange.push_back(xsecBrSamplesToChange[i]);
//  }

 //  copyV2Vs (NameAllMasses, vNameAllMasses, sizeof(xsecBrSamplesToChange)/sizeof(std::string));
 //  std::vector< std::string > vxsecBrSamplesToChange (xsecBrSamplesToChange, xsecBrSamplesToChange + sizeof(xsecBrSamplesToChange) / sizeof(std::string) );
 
 ///---- prepare xsections ----
 std::map <float, float> xSecBR_ggH;
 std::map <float, float> xSecBR_qqH;
 std::map <float, float> xSecBR_WH;
 std::map <float, float> xSecBR_ZH;
 std::map <float, float> xSecBR_VH;
 
 //
 // parse xsec file
 //
 std::ifstream ifs;
 TString nameXsec;
  if (sqrts == 8) {
   nameXsec = Form ("xs_br_h_ecm8tev.txt");
  }
  else {
   nameXsec = Form ("xs_br_h_ecm7tev.txt");
  }
 
 ifs.open(nameXsec.Data());
 assert(ifs.is_open());
 std::string linexsec;
 while(getline(ifs,linexsec)) {
  float m, ggh, qqh, wh, zh, tth, brhww, brhzz, brhbb, brhtt, brhgg, brhzg;
  std::stringstream ss(linexsec);
  ss >> m >> ggh >> qqh >> wh >> zh >> tth >> brhww >> brhzz >> brhbb >> brhtt >> brhgg >> brhzg; 
  xSecBR_ggH[m] = ggh*brhww;
  xSecBR_qqH[m] = qqh*brhww;
  xSecBR_WH[m]  = wh*brhww;
  xSecBR_ZH[m]  = zh*brhww;

  xSecBR_VH[m]  = wh*brhww + zh*brhww;  //----> VH = WH+ZH
 }
 ifs.close();
 
 std::vector< std::map <float, float> > xSecBR;
 xSecBR.push_back(xSecBR_ggH);
 xSecBR.push_back(xSecBR_qqH);
 xSecBR.push_back(xSecBR_WH);
 xSecBR.push_back(xSecBR_ZH);
 xSecBR.push_back(xSecBR_WH);
 
 
 
//  templateDC
// e.g.  hwwof_2j_shape.txt
 
 
 
 for (int iMass = 0; iMass < vNameAllMasses.size(); iMass++) {
  std::cout << " iMass = " << iMass << " : " << vNameAllMasses.size() << std::endl;
  std::pair< std::pair <int, float> , std::pair <int, float> > temp_pair = GetCloserMass(vAllMasses.at(iMass), vTemplateMasses);
  int loMass = temp_pair.first.first;
  int hiMass = temp_pair.second.first;
  float dRloMass = temp_pair.first.second;
  float dRhiMass = temp_pair.second.second;
  
  
  std::cout << "[" << iMass << ":" << vNameAllMasses.size()-1 << "] = " << vAllMasses.at(iMass) << " -> [" << loMass << "]";
  std::cout << " < X < [" << hiMass << "]";
  
  if (loMass == -1 && hiMass == -1) { ///---- no "close" mass point
   continue;
  }
  
  if (vAllMasses.at(iMass) == vTemplateMasses.at(loMass)) { ///---- if it is an already set mass, skip!
   continue;
  }

  if (vAllMasses.at(iMass) == vTemplateMasses.at(hiMass)) { ///---- if it is an already set mass, skip!
   continue;
  }
  
  std::cout << " = " << vNameTemplateMasses.at(loMass) << std::endl;
 
  
  TString inputDataCardLo = Form ("%s/%s",vNameTemplateMasses.at(loMass).c_str(),templateDC.c_str());
  std::string inputDataCardStringLo = inputDataCardLo.Data();
  TString inputDataCardHi = Form ("%s/%s",vNameTemplateMasses.at(hiMass).c_str(),templateDC.c_str());
  std::string inputDataCardStringHi = inputDataCardHi.Data();
  
  ///---- low datacard
  std::string buffer;
  std::cout << " read :: " << inputDataCardStringLo.c_str() << std::endl;
  std::ifstream fileDataLo (inputDataCardStringLo.c_str());  
  
  ///---- skip first lines
//   for (int ie = 0; ie<11; ie++) {
  for (int ie = 0; ie<13; ie++) {
   getline(fileDataLo,buffer);
  }  
  
  ///---- get samples names
  std::vector <std::string> vSamples;
//   process                                                   ggH       qqH       ggWW      VgS       Vg        WJet      Top       WW        WWewk     VV        DYTT      
  int numSample = 0;
  getline(fileDataLo,buffer);
  std::stringstream lineSample( buffer ); 
  std::string tempChar;
  std::string tempCharStr;
  lineSample >> tempChar; // process
  std::string tempName = "process";    
  
  while (1) {
   lineSample >> tempChar;
   
   if (tempName != tempChar) {
    vSamples.push_back (tempChar);
    tempName = tempChar;
    numSample++;
   }
   else {
    break;
   }
  }
  
  
  std::cout << " vSamples size = " << vSamples.size() << std::endl;
  
  
  ///---- check samples to change ----
  
  std::vector<int> vIntToChange; //---- number to change:      number in vSamples
  std::vector<int> vIntToChangeWith; //---- with which number: number in vSamplesToChange
  
  for (int iSample = 0; iSample < vSamples.size(); iSample++) {
   for (int iSampleToChange = 0; iSampleToChange < vSamplesToChange.size(); iSampleToChange++) {
    if (vSamplesToChange.at(iSampleToChange) == vSamples.at(iSample)) {
     vIntToChange.push_back(iSample);
     vIntToChangeWith.push_back(iSampleToChange);
    }
   }
  }
  
  
  ///---- skip one line ----
  getline(fileDataLo,buffer);
  
  
  ///---- get expected rate of events
  std::vector<float> vRate;
  std::vector<double> vScaleLo;
  std::vector<double> vScaleHi;
  
  getline(fileDataLo,buffer);
  std::stringstream line( buffer ); 
  line >> tempChar; //    rate
  for (int iSample = 0; iSample < vSamples.size(); iSample++) {
   double temp;
   line >> temp;
   vRate.push_back(temp);
   vScaleLo.push_back(0);
   vScaleHi.push_back(0);
  }
  
  
  
  
  
  
  
  ///---- high datacard
  std::cout << " read :: " << inputDataCardStringHi.c_str() << std::endl;
  std::ifstream fileDataHi (inputDataCardStringHi.c_str());  
  
  ///---- skip first lines
//   for (int ie = 0; ie<11; ie++) {
  for (int ie = 0; ie<13; ie++) {
   getline(fileDataHi,buffer);
  }  
  
  ///---- get samples names
  vSamples.clear();
  //   process                                                   ggH       qqH       ggWW      VgS       Vg        WJet      Top       WW        WWewk     VV        DYTT      
  numSample = 0;
  getline(fileDataHi,buffer);
  std::stringstream lineSampleHi( buffer ); 
  lineSampleHi >> tempChar; // process
  tempName = "process";    
  
  while (1) {
   lineSampleHi >> tempChar;
   
   if (tempName != tempChar) {
    vSamples.push_back (tempChar);
    tempName = tempChar;
    numSample++;
   }
   else {
    break;
   }
  }
  
  ///---- check samples to change ----
  
  std::vector<int> vIntToChangeHi; //---- number to change:      number in vSamples
  std::vector<int> vIntToChangeWithHi; //---- with which number: number in vSamplesToChange
  
  for (int iSample = 0; iSample < vSamples.size(); iSample++) {
   for (int iSampleToChange = 0; iSampleToChange < vSamplesToChange.size(); iSampleToChange++) {
    if (vSamplesToChange.at(iSampleToChange) == vSamples.at(iSample)) {
     vIntToChangeHi.push_back(iSample);
     vIntToChangeWithHi.push_back(iSampleToChange);
    }
   }
  }
  
  
  ///---- skip one line ----
  getline(fileDataHi,buffer);
  
  
  ///---- get expected rate of events
  std::vector<float> vRateHi;
  getline(fileDataHi,buffer);
  std::stringstream lineHi( buffer ); 
  lineHi >> tempChar; //    rate
  for (int iSample = 0; iSample < vSamples.size(); iSample++) {
   double temp;
   lineHi >> temp;
   vRateHi.push_back(temp);
  }
  
  
//   std::cout << "here" << std::endl;
   
  
  ///---- modify the rate according to BR*xsec
  
  for (int iSample = 0; iSample < vSamples.size(); iSample++) {
   for (int iIntToChange = 0; iIntToChange < vIntToChange.size(); iIntToChange++) {
    if ( vIntToChange.at(iIntToChange) == iSample)) {
     double tempRateLo = vRate  .at(iSample);
     double tempRateHi = vRateHi.at(iSample);
     float dRtot = dRloMass + dRhiMass;
//      std::cout << " vIntToChangeWith  .size() = " << vIntToChangeWith  .size() << std::endl;
//      std::cout << " vIntToChangeWithHi.size() = " << vIntToChangeWithHi.size() << std::endl;
//      std::cout << "here iSample = " << iSample << "  iIntToChange = " << iIntToChange << " vIntToChangeWithHi.at(" << iIntToChange << ") = " << vIntToChangeWithHi.at(iIntToChange) << std::endl;
     
     double scaleLo = dRhiMass/dRtot * (xSecBR.at(vIntToChangeWith  .at(iIntToChange))) [ vAllMasses.at(iMass) ] / (xSecBR.at(vIntToChangeWith  .at(iIntToChange))) [ vTemplateMasses.at(loMass) ];
     double scaleHi = dRloMass/dRtot * (xSecBR.at(vIntToChangeWithHi.at(iIntToChange))) [ vAllMasses.at(iMass) ] / (xSecBR.at(vIntToChangeWithHi.at(iIntToChange))) [ vTemplateMasses.at(hiMass) ];
     if (scaleLo == 0) {
      std::cout << (xSecBR.at(vIntToChangeWith  .at(iIntToChange))) [ vAllMasses.at(iMass) ] << " / " << (xSecBR.at(vIntToChangeWith  .at(iIntToChange))) [ vTemplateMasses.at(loMass) ] << " *** error: scale lo = 0" << std::endl;      
     }
     if (scaleHi == 0) {
      std::cout << (xSecBR.at(vIntToChangeWithHi.at(iIntToChange))) [ vAllMasses.at(iMass) ] << " / " << (xSecBR.at(vIntToChangeWithHi.at(iIntToChange))) [ vTemplateMasses.at(hiMass) ] << " *** error: scale hi = 0" << std::endl;      
     }
     vRate.at(iSample) = tempRateLo * scaleLo + tempRateHi * scaleHi;
     vScaleLo.at(iSample) = scaleLo;
     vScaleHi.at(iSample) = scaleHi;
    }
   }
  }
  

//   std::cout << "here" << std::endl;
  
  
  ///---- update histograms
  
  
  TString inputRootFileLo = Form ("%s/shapes/hww-%sfb.mH%s.%s.root",vNameTemplateMasses.at(loMass).c_str(),lumi.c_str(),vNameTemplateMasses.at(loMass).c_str(),tag.c_str());
  TFile * old_file_Lo = new TFile(inputRootFileLo.Data());
  TString inputRootFileHi = Form ("%s/shapes/hww-%sfb.mH%s.%s.root",vNameTemplateMasses.at(hiMass).c_str(),lumi.c_str(),vNameTemplateMasses.at(hiMass).c_str(),tag.c_str());
  TFile * old_file_Hi = new TFile(inputRootFileHi.Data());
  
  TFile* new_file = TFile::Open("temp.root", "RECREATE");  // my output file
  std::vector <std::string> listOfChangedHistos;
  
  
  for (int iSample = 0; iSample < vSamples.size(); iSample++) {
   for (int iIntToChange = 0; iIntToChange < vIntToChange.size(); iIntToChange++) {
    if ( vIntToChange.at(iIntToChange) == iSample)) {
     double tempRate = vRate.at(iSample);
     double scaleLo = vScaleLo.at(iSample);
     double scaleHi = vScaleHi.at(iSample);

     TList* list_Lo = (TList*) old_file_Lo->GetListOfKeys() ;
     TIter nextLo(old_file_Lo->GetListOfKeys()) ;
     TKey* key_Lo ;
     TObject* obj ;
     
     ///---- lo
     while ( key_Lo = (TKey*) nextLo() ) {
      obj = key_Lo->ReadObj() ;
      if (   (strcmp(obj->IsA()->GetName(),"TProfile")!=0)
       && (!obj->InheritsFrom("TH2"))
       && (!obj->InheritsFrom("TH1")) 
       ) {
        //     
        //      printf("Object %s is not 1D or 2D histogram : will not be converted\n",obj->GetName()) ;
        //      
       }
       //     
       //     printf("Histo name:%s title:%s\n",obj->GetName(),obj->GetTitle());
      //    
      
//       std::cout << "          --- obj->GetName() = " << obj->GetName() << std::endl;      
      std::string stringToParse   = obj->GetName();
      std::string stringToLookFor = vSamplesToChange.at( vIntToChangeWith.at(iIntToChange) );
      
      // different member versions of find in the same order as above:
      std::size_t found = stringToParse.find(stringToLookFor);

      //---- ggH_SM, qqH_SM, ... not to be modified!
      std::string stringToLookFor_SM = vSamplesToChange.at( vIntToChangeWith.at(iIntToChange) );
      stringToLookFor_SM.append ("_SM");
      std::size_t found_SM = stringToParse.find(stringToLookFor_SM);
      
      //----    if ggH                   but not  ggH_SM
      if ((found!=std::string::npos) && (found_SM==std::string::npos)) {
       //     std::cout << "first 'XXX' found at: " << found << '\n';
       
       listOfChangedHistos.push_back(stringToParse);
       TH1F* objH = (TH1F*) obj->Clone();
       
//        std::cout << " >> Integral = " << objH->Integral();
       objH->Scale(scaleLo); ///----> scale
//        std::cout << " -> " << objH->Integral() << std::endl;;
       objH->Write();
      }
      
     }
     
     
     
     ///---- hi
     while ( key_Hi = (TKey*) nextLo() ) {
      obj = key_Hi->ReadObj() ;
      if (   (strcmp(obj->IsA()->GetName(),"TProfile")!=0)
       && (!obj->InheritsFrom("TH2"))
       && (!obj->InheritsFrom("TH1")) 
      ) {
       //     
       //      printf("Object %s is not 1D or 2D histogram : will not be converted\n",obj->GetName()) ;
       //      
      }
      //     
      //     printf("Histo name:%s title:%s\n",obj->GetName(),obj->GetTitle());
      //    
      
      //       std::cout << "          --- obj->GetName() = " << obj->GetName() << std::endl;      
      std::string stringToParse   = obj->GetName();
      std::string stringToLookFor = vSamplesToChange.at( vIntToChangeWith.at(iIntToChange) );
      
      // different member versions of find in the same order as above:
      std::size_t found = stringToParse.find(stringToLookFor);
      
      //---- ggH_SM, qqH_SM, ... not to be modified!
      std::string stringToLookFor_SM = vSamplesToChange.at( vIntToChangeWith.at(iIntToChange) );
      stringToLookFor_SM.append ("_SM");
      std::size_t found_SM = stringToParse.find(stringToLookFor_SM);
      
      //----    if ggH                   but not  ggH_SM
      if ((found!=std::string::npos) && (found_SM==std::string::npos)) {
       //     std::cout << "first 'XXX' found at: " << found << '\n';
       
       listOfChangedHistos.push_back(stringToParse);
       TH1F* objH = (TH1F*) obj->Clone("TEMP");
       
       //        std::cout << " >> Integral = " << objH->Integral();
       objH->Scale(scaleHi); ///----> scale
       std::cout << " -> " << objH->Integral() << std::endl;;
       
       
       ///---- join lo/hi
       
       TH1F* tempToJoin = (TH1F*) new_file->Get(stringToParse.c_str());
       tempToJoin.Add((TH1F*) objH);
       tempToJoin->Write();
             
//        objH->Write();
      }
      
     }
     
     
    }
   }
  }
  
  
  ///----> copy the remaining histograms  (from "Lo", they need to be the same!)

  TList* list = (TList*) old_file_Lo->GetListOfKeys() ;
  TIter next(old_file_Lo->GetListOfKeys()) ;
  TKey* key ;
  TObject* obj ;
  
  while ( key = (TKey*) next() ) {
   obj = key->ReadObj() ;
   if (   (strcmp(obj->IsA()->GetName(),"TProfile")!=0)
    && (!obj->InheritsFrom("TH2"))
    && (!obj->InheritsFrom("TH1")) 
   ) {
    //     
   }
   std::string stringToParse   = obj->GetName();
   bool alreadySaved = false;
   for (int iHisto = 0; iHisto < listOfChangedHistos.size(); iHisto++) {
    if (stringToParse == listOfChangedHistos.at(iHisto)) {
     alreadySaved = true;
    }
   }
   
   if (!alreadySaved) {
    TH1F* objH = (TH1F*) obj->Clone();
    objH->Write(); 
   }   
  }
  
  
  
  new_file->Close();
  delete old_file_Lo;
  delete old_file_Hi;
  
  
  
  
  ///---- create new datacard ----
  TString CommandToExec;
  
  ///---- 1) create new folder
  CommandToExec = Form("mkdir %s",vNameAllMasses.at(iMass).c_str());
  //   std::cout << CommandToExec.Data() << std::endl;
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("mkdir %s/shapes",vNameAllMasses.at(iMass).c_str());
  //   std::cout << CommandToExec.Data() << std::endl;
  gSystem->Exec(CommandToExec);  
  
  
  ///---- 2) copy root file
  CommandToExec = Form("mv temp.root %s/shapes/hww-%sfb.mH%s.%s.root",vNameAllMasses.at(iMass).c_str(),lumi.c_str(),vNameTemplateMasses.at(loMass).c_str(),tag.c_str());
  //   std::cout << CommandToExec.Data() << std::endl;
  gSystem->Exec(CommandToExec);  
  
  ///---- 3) create datacard
    
//   CommandToExec = Form("head -13  %s > temp_head_DC.txt",inputDataCardStringLo.c_str());
  CommandToExec = Form("head -15  %s > temp_head_DC.txt",inputDataCardStringLo.c_str());
  //   std::cout << CommandToExec.Data() << std::endl;
  gSystem->Exec(CommandToExec);  
  
 
  std::ofstream myfile;
  myfile.open ("temp_Rate.txt");
  myfile << std::setw(58-9) << "     rate    ";
  for (int iSample = 0; iSample < vSamples.size(); iSample++) {
   myfile << std::setprecision(4) << std::setw(10) << vRate.at(iSample);
  }
  myfile << std::endl;    
  myfile.close(); 
  
  
//   CommandToExec = Form("tail -n+15 %s > temp_queue_DC.txt",inputDataCardStringLo.c_str());
  CommandToExec = Form("tail -n+17 %s > temp_queue_DC.txt",inputDataCardStringLo.c_str());
  //   std::cout << CommandToExec.Data() << std::endl;
  gSystem->Exec(CommandToExec);  
  
  CommandToExec = Form("cat temp_head_DC.txt temp_Rate.txt temp_queue_DC.txt > %s/%s",vNameAllMasses.at(iMass).c_str(),templateDC.c_str());
  //   std::cout << CommandToExec.Data() << std::endl;
  gSystem->Exec(CommandToExec);  
  

  std::cout << " write : " << vNameAllMasses.at(iMass) << "/" << templateDC << std::endl;;
  
 }
 
 
 //  r00t -q /home/andrea/Dropbox/VBF/BrazilianPlots/Interpolation.cxx\(\"hwwof_2j_shape.txt\"\)
//  r00t -q /home/andrea/Dropbox/VBF/BrazilianPlots/Interpolation.cxx\(\"hwwof_vh2j_shape_8TeV.txt\",\"19.47\",\"of_vh2j_shape\",8,0\)
 
 
 std::cout << " #### end #### " << std::endl;
//  gApplication->Terminate(0);
}


