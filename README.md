InterpolationDatacards
======================

Interpolate datacards

    - VBF
    - VH

Datacards are 5 GeV steps

    - Transform datacards from latino format to svn commit format
    - interpolate to the nearest point using \sigma * BR scaling


Code previously in ~/Dropbox/VBF/BrazilianPlots/Interpolation.cxx now committed to git here


Example in 

    amassiro@amassiro-XPS-L421X:~/Cern/Code/VBF/RepositoryDataCardNewLumi/summer2013/InterpolationDatacards
    amassiro@amassiro-XPS-L421X:~/Cern/Code/VBF/RepositoryDataCardNewLumi/summer2013/TRANSFORM




Where:

    xps13
    /home/amassiro/Cern/Code/VBF/InterpolationDatacards

    

# Interpolation of efficiencies
    
    cp -r  ../RepositoryDataCardNewLumi/summer2013/couplings/hww2l2v/* ./
    rm -r ???.?/
    ls -d ???/ | grep -v 110 | grep -v 115 | grep -v 120 | grep -v 125 | grep -v 130 | grep -v 135 | grep -v 140 | grep -v 145 \
            | grep -v 150 | grep -v 155 | grep -v 160 | grep -v 170 | grep -v 180 | grep -v 190 | grep -v 200 | grep -v 250 | grep -v 300 \
            | awk '{print "rm -r "$1}' | /bin/sh
    r00t -q InterpolationEfficiency.cxx\(\"hwwof_2j_shape_8TeV.txt\",\"19.36\",\"of_2j_shape_mll\",8\)

    //----    8 = 8 TeV, 0 = no low mass, 0 = no interpolate histograms
    r00t -q InterpolationEfficiency.cxx\(\"hwwof_2j_shape_8TeV.txt\",\"19.36\",\"of_2j_shape_mll\",8,0,0\)
    
    
======================

# VH

Copy locally the datacards:

    scp amassiro@cmsmi4.cern.ch:/data2/amassiro/VBF/Summer12/28Jan2013/Shape/playground/vhCutBased?F.tgz ./
    scp amassiro@cmsmi4.cern.ch:/data2/amassiro/VBF/Summer12/28Jan2013/Shape/playground/vhCutBased2011?F.tgz ./
    scp amassiro@cmsmi4.cern.ch:/data2/amassiro/VBF/Summer12/28Jan2013/Shape/playground/vhMllDFbbb.tgz ./

Prepare:

    rm -r ???/
    rm -r ???.?/


    mkdir 110
    mkdir 115
    mkdir 120
    mkdir 125
    mkdir 130
    mkdir 135
    mkdir 140
    mkdir 145
    mkdir 150
    mkdir 155
    mkdir 160
    mkdir 170
    mkdir 180
    mkdir 190
    mkdir 200
    mkdir 250
    mkdir 300
    

#### to change name to root file for shape analysis

    tar -xvf vhMllDFbbb.tgz
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-19.36fb.mH"$1".of_vh2j_shape.txt "$1"/hwwof_vh2j_shape_8TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-19.36fb.mH"$1".of_vh2j_shape.root "$1"/shapes/"}' | /bin/sh

    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "sed 's/of_vh2j_shape/of_vh2j_shape_mll/g' "$1"/hwwof_vh2j_shape_8TeV.txt > prova.txt;   mv prova.txt "$1"/hwwof_vh2j_shape_8TeV.txt "}' | /bin/sh
    ls ???/shapes/*.root --colo=none | tr "/" " " | sed 's/.root//g' |  awk '{print "mv "$1"/shapes/"$3".root "$1"/shapes/"$3"_mll.root "}' | /bin/sh


#### then extract cut based

    tar -xvf vhCutBasedDF.tgz
    
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/hww-19.36fb.mH"$1".of_vh2j_shape.txt "$1"/hwwof_vh2j_cut_8TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-19.36fb.mH"$1".of_vh2j_shape.root "$1"/shapes/"}' | /bin/sh
    

    tar -xvf vhCutBasedSF.tgz
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-19.36fb.mH"$1".sf_vh2j_shape.txt "$1"/hwwsf_vh2j_cut_8TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-19.36fb.mH"$1".sf_vh2j_shape.root "$1"/shapes/"}' | /bin/sh
    


    tar -xvf vhCutBased2011DF.tgz
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-4.92fb.mH"$1".of_vh2j_shape.txt "$1"/hwwof_vh2j_cut_7TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-4.92fb.mH"$1".of_vh2j_shape.root "$1"/shapes/"}' | /bin/sh
    

    tar -xvf vhCutBased2011SF.tgz
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-4.92fb.mH"$1".sf_vh2j_shape.txt "$1"/hwwsf_vh2j_cut_7TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-4.92fb.mH"$1".sf_vh2j_shape.root "$1"/shapes/"}' | /bin/sh

    
    
    

#### interpolate ####

    r00t -q Interpolation.cxx\(\"hwwof_vh2j_cut_8TeV.txt\",\"19.36\",\"of_vh2j_shape\",8,0\)
    r00t -q Interpolation.cxx\(\"hwwsf_vh2j_cut_8TeV.txt\",\"19.36\",\"sf_vh2j_shape\",8,0\)

    r00t -q Interpolation.cxx\(\"hwwof_vh2j_cut_7TeV.txt\",\"4.92\",\"of_vh2j_shape\",7,0\)
    r00t -q Interpolation.cxx\(\"hwwsf_vh2j_cut_7TeV.txt\",\"4.92\",\"sf_vh2j_shape\",7,0\)

    r00t -q Interpolation.cxx\(\"hwwof_vh2j_shape_8TeV.txt\",\"19.36\",\"of_vh2j_shape_mll\",8,0\)
 
    
#### modify datacards

remove TTH

    cd ../ModificationDatacards/
    bash examples/doRemoveTTH.sh

Now copy the root files

    cd ../InterpolationDatacards/
    ls -d ???/   | awk '{print "cp "$1"/shapes/*.root ../searches/vhww/"$1"/shapes/"}' | /bin/sh
    ls -d ???/   | awk '{print "cp "$1"/*.txt ../searches/vhww/"$1"/"}' | /bin/sh
    ls -d ???.?/ | awk '{print "cp "$1"/shapes/*.root ../searches/vhww/"$1"/shapes/"}' | /bin/sh
    ls -d ???.?/ | awk '{print "cp "$1"/*.txt ../searches/vhww/"$1"/"}' | /bin/sh


     
scale _SH in searches datacard

    cd ../ModificationDatacards/
    bash examples/doScale125to126GeV.sh
    

### create couplings datacards (remove _SM processes)

    cd ../ModificationDatacards/
    bash examples/doTransformSVNDatacardsSearchesCouplings.sh

Now copy the root files

    cd ../InterpolationDatacards/
    ls -d */ | awk '{print "cp "$1"/shapes/*.root ../couplings/vhww/"$1"/shapes/"}' | /bin/sh
    ls -d */ | awk '{print "cp "$1"/*.txt ../couplings/vhww/"$1"/"}' | /bin/sh


### commit

    # to clean:    rm  */*_vh2j*.txt */shapes/*vh2j*.root
    
    cd ../searches/vhww
    svn commit -m "" */*_vh2j*.txt */shapes/*vh2j*.root
    cd ../../couplings/vhww
    svn commit -m "" */*_vh2j*.txt */shapes/*vh2j*.root




    
    
    
======================

# VBF

copy file:

    scp amassiro@cmsmi4.cern.ch:/data2/amassiro/VBF/Summer12/28Jan2013/Shape/playground/vbfMllDF.tgz ./
    scp amassiro@cmsmi4.cern.ch:/data2/amassiro/VBF/Summer12/28Jan2013/Shape/playground/vbfMll2011DF.tgz ./

prepare:
    
    rm -r ???.?/
    rm -r ???/

    mkdir 110
    mkdir 115
    mkdir 120
    mkdir 125
    mkdir 130
    mkdir 135
    mkdir 140
    mkdir 145
    mkdir 150
    mkdir 155
    mkdir 160
    mkdir 170
    mkdir 180
    mkdir 190
    mkdir 200
    mkdir 250
    mkdir 300
    mkdir 350
    mkdir 400
    mkdir 450
    mkdir 500
    mkdir 550
    mkdir 600
    
    
    tar -xvf vbfMllDF.tgz
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-19.36fb.mH"$1".of_2j_shape.txt "$1"/hwwof_2j_shape_8TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-19.36fb.mH"$1".of_2j_shape.root "$1"/shapes/"}' | /bin/sh

    
    tar -xvf vbfMll2011DF.tgz
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-4.92fb.mH"$1".of_2j_shape.txt "$1"/hwwof_2j_shape_7TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-4.92fb.mH"$1".of_2j_shape.root "$1"/shapes/"}' | /bin/sh
    
    
#### to change name to root file for shape analysis
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "sed 's/of_2j_shape/of_2j_shape_mll/g' "$1"/hwwof_2j_shape_8TeV.txt > prova.txt;   mv prova.txt "$1"/hwwof_2j_shape_8TeV.txt "}' | /bin/sh
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "sed 's/of_2j_shape/of_2j_shape_mll/g' "$1"/hwwof_2j_shape_7TeV.txt > prova.txt;   mv prova.txt "$1"/hwwof_2j_shape_7TeV.txt "}' | /bin/sh
    ls ???/shapes/*.root --colo=none | tr "/" " " | sed 's/.root//g' |  awk '{print "mv "$1"/shapes/"$3".root "$1"/shapes/"$3"_mll.root "}' | /bin/sh

    
#### then extract cut based
#### not required! Cut based provided by Guillelmo

    tar -xvf vbfCutBasedDF.tgz
    
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/hww-19.36fb.mH"$1".of_2j_shape.txt "$1"/hwwof_2j_cut_8TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-19.36fb.mH"$1".of_2j_shape.root "$1"/shapes/"}' | /bin/sh
    

    tar -xvf vbfCutBasedSF.tgz
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-19.36fb.mH"$1".sf_2j_shape.txt "$1"/hwwsf_2j_cut_8TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-19.36fb.mH"$1".sf_2j_shape.root "$1"/shapes/"}' | /bin/sh
    


    tar -xvf vbfCutBased2011DF.tgz
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-4.92fb.mH"$1".of_2j_shape.txt "$1"/hwwof_2j_cut_7TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-4.92fb.mH"$1".of_2j_shape.root "$1"/shapes/"}' | /bin/sh
    

    tar -xvf vbfCutBased2011SF.tgz
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-4.92fb.mH"$1".sf_2j_shape.txt "$1"/hwwsf_2j_cut_7TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-4.92fb.mH"$1".sf_2j_shape.root "$1"/shapes/"}' | /bin/sh



    
        
#### interpolate ####

    r00t -q Interpolation.cxx\(\"hwwof_2j_shape_8TeV.txt\",\"19.36\",\"of_2j_shape_mll\",8\)
    r00t -q Interpolation.cxx\(\"hwwof_2j_shape_7TeV.txt\",\"4.92\",\"of_2j_shape_mll\",7\)

#### not required! Cut based provided by Guillelmo

    r00t -q Interpolation.cxx\(\"hwwof_2j_cut_8TeV.txt\",\"19.36\",\"of_2j_shape\",8\)
    r00t -q Interpolation.cxx\(\"hwwsf_2j_cut_8TeV.txt\",\"19.36\",\"sf_2j_shape\",8\)

    r00t -q Interpolation.cxx\(\"hwwof_2j_cut_7TeV.txt\",\"4.92\",\"of_2j_shape\",7\)
    r00t -q Interpolation.cxx\(\"hwwsf_2j_cut_7TeV.txt\",\"4.92\",\"sf_2j_shape\",7\)

    
#### modify datacards

remove TTH

    cd ../ModificationDatacards/
    bash examples/doRemoveTTH.sh

Now copy the root files

    cd ../InterpolationDatacards/
    ls -d ???/   | awk '{print "cp "$1"/shapes/*.root ../searches/hww2l2v/"$1"/shapes/"}' | /bin/sh
    ls -d ???/   | awk '{print "cp "$1"/*.txt ../searches/hww2l2v/"$1"/"}' | /bin/sh
    ls -d ???.?/ | awk '{print "cp "$1"/shapes/*.root ../searches/hww2l2v/"$1"/shapes/"}' | /bin/sh
    ls -d ???.?/ | awk '{print "cp "$1"/*.txt ../searches/hww2l2v/"$1"/"}' | /bin/sh


scale _SH in searches datacard

    cd ../ModificationDatacards/
    bash examples/doScale125to126GeV_vbf.sh
    

### create couplings datacards (remove _SM processes)

    cd ../ModificationDatacards/
    bash examples/doTransformSVNDatacardsSearchesCouplings.sh

Now copy the root files

    cd ../InterpolationDatacards/
    ls -d */ | awk '{print "cp "$1"/shapes/*.root ../couplings/hww2l2v/"$1"/shapes/"}' | /bin/sh
    ls -d */ | awk '{print "cp "$1"/*.txt ../couplings/hww2l2v/"$1"/"}' | /bin/sh


### commit

    # to clean:    rm  */*_2j_shape*.txt */shapes/*2j_shape*.root
    
    cd ../searches/hww2l2v
    svn commit -m "" */*_2j_shape*.txt */shapes/*2j_shape*.root
    cd ../couplings/hww2l2v
    svn commit -m "" */*_2j_shape*.txt */shapes/*2j_shape*.root




    
    
    
    