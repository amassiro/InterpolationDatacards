InterpolationDatacards
======================

Interpolate datacards

- VBF
- VH

Datacards are 5 GeV steps

- Transform datacards from latino format to svn commit format
- interpolate to the nearest point using \sigma * BR scaling


Code previously in ~/Dropbox/VBF/BrazilianPlots/Interpolation.cxx now committed to git here


Example in amassiro@amassiro-XPS-L421X:~/Cern/Code/VBF/RepositoryDataCardNewLumi/summer2013/InterpolationDatacards
amassiro@amassiro-XPS-L421X:~/Cern/Code/VBF/RepositoryDataCardNewLumi/summer2013/TRANSFORM







### VBF ###

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
    
    
#### to change name to root file for shape analysis ####
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "sed 's/of_2j_shape/of_2j_shape_mll/g' "$1"/hwwof_2j_shape_8TeV.txt > prova.txt;   mv prova.txt "$1"/hwwof_2j_shape_8TeV.txt "}' | /bin/sh
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "sed 's/of_2j_shape/of_2j_shape_mll/g' "$1"/hwwof_2j_shape_7TeV.txt > prova.txt;   mv prova.txt "$1"/hwwof_2j_shape_7TeV.txt "}' | /bin/sh
    ls ???/shapes/*.root --colo=none | tr "/" " " | sed 's/.root//g' |  awk '{print "mv "$1"/shapes/"$3".root "$1"/shapes/"$3"_mll.root "}' | /bin/sh
    
    
#### interpolate ####

    r00t -q Interpolation.cxx\(\"hwwof_2j_shape_8TeV.txt\",\"19.36\",\"of_2j_shape_mll\",8\)
    r00t -q Interpolation.cxx\(\"hwwof_2j_shape_7TeV.txt\",\"4.92\",\"of_2j_shape_mll\",7\)
    
    
    
### couplings if "No _SM"

    ls -d */ | awk '{print "cp "$1"/*.txt ../couplings/hww2l2v/"$1"/"}' | /bin/sh
    ls -d */ | awk '{print "cp "$1"/shapes/*.root ../couplings/hww2l2v/"$1"/shapes/"}' | /bin/sh

### couplings if "Yes _SM"

    ls -d */ | awk '{print "cp "$1"/*.txt ../searches/hww2l2v/"$1"/"}' | /bin/sh
    ls -d */ | awk '{print "cp "$1"/shapes/*.root ../searches/hww2l2v/"$1"/shapes/"}' | /bin/sh




### VH ###

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
    

    tar -xvf vhCutBasedDF.tgz
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-19.36fb.mH"$1".of_vh2j_shape.txt "$1"/hwwof_vh2j_cut_8TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-19.36fb.mH"$1".of_vh2j_shape.root "$1"/shapes/"}' | /bin/sh
    

    tar -xvf vhCutBasedSF.tgz
    
    ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-19.36fb.mH"$1".sf_vh2j_shape.txt "$1"/hwwsf_vh2j_cut_8TeV.txt"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
    ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-19.36fb.mH"$1".sf_vh2j_shape.root "$1"/shapes/"}' | /bin/sh
    




#### interpolate ####

    r00t -q Interpolation.cxx\(\"hwwof_vh2j_cut_8TeV.txt\",\"19.36\",\"of_vh2j_shape\",8,0\)
    r00t -q Interpolation.cxx\(\"hwwsf_vh2j_cut_8TeV.txt\",\"19.36\",\"sf_vh2j_shape\",8,0\)


### couplings if "No _SM"

    ls -d */ | awk '{print "cp "$1"/*.txt ../couplings/vhww/"$1"/"}' | /bin/sh
    ls -d */ | awk '{print "cp "$1"/shapes/*.root ../couplings/vhww/"$1"/shapes/"}' | /bin/sh


### searches if "Yes _SM"

    ls -d */ | awk '{print "cp "$1"/*.txt ../searches/vhww/"$1"/"}' | /bin/sh
    ls -d */ | awk '{print "cp "$1"/shapes/*.root ../searches/vhww/"$1"/shapes/"}' | /bin/sh





tar -xvf vhCutBased2011DF.tgz

ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-4.92fb.mH"$1".of_vh2j_shape.txt "$1"/hwwof_vh2j_cut_7TeV.txt"}' | /bin/sh
ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-4.92fb.mH"$1".of_vh2j_shape.root "$1"/shapes/"}' | /bin/sh


tar -xvf vhCutBased2011SF.tgz

ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-4.92fb.mH"$1".sf_vh2j_shape.txt "$1"/hwwsf_vh2j_cut_7TeV.txt"}' | /bin/sh
ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-4.92fb.mH"$1".sf_vh2j_shape.root "$1"/shapes/"}' | /bin/sh




#### interpolate ####
r00t -q Interpolation.cxx\(\"hwwof_vh2j_cut_7TeV.txt\",\"4.92\",\"of_vh2j_shape\",7,0\)
r00t -q Interpolation.cxx\(\"hwwsf_vh2j_cut_7TeV.txt\",\"4.92\",\"sf_vh2j_shape\",7,0\)









### VH mll ###

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



tar -xvf vhMllDFbbb.tgz

ls ???/ -d --colo=none | tr "/" " " | awk '{print "cp datacards/hww-19.36fb.mH"$1".of_vh2j_shape.txt "$1"/hwwof_vh2j_shape_8TeV.txt"}' | /bin/sh
ls ???/ -d --colo=none  | tr "/" " " | awk '{print "mkdir "$1"/shapes"}' | /bin/sh
ls ???/ -d --colo=none  | tr "/" " " | awk '{print "cp datacards/shapes/hww-19.36fb.mH"$1".of_vh2j_shape.root "$1"/shapes/"}' | /bin/sh




#### to change name to root file for shape analysis ####
#### VH ####
ls ???/ -d --colo=none | tr "/" " " | awk '{print "sed 's/of_vh2j_shape/of_vh2j_shape_mll/g' "$1"/hwwof_vh2j_shape_8TeV.txt > prova.txt;   mv prova.txt "$1"/hwwof_vh2j_shape_8TeV.txt "}' | /bin/sh
ls ???/shapes/*.root --colo=none | tr "/" " " | sed 's/.root//g' |  awk '{print "mv "$1"/shapes/"$3".root "$1"/shapes/"$3"_mll.root "}' | /bin/sh





#### interpolate ####

r00t -q Interpolation.cxx\(\"hwwof_vh2j_shape_8TeV.txt\",\"19.36\",\"of_vh2j_shape_mll\",8,0\)



### couplings if "No _SM"
ls -d */ | awk '{print "cp "$1"/*.txt ../couplings/vhww/"$1"/"}' | /bin/sh
ls -d */ | awk '{print "cp "$1"/shapes/*.root ../couplings/vhww/"$1"/shapes/"}' | /bin/sh


### searches if "Yes _SM"
ls -d */ | awk '{print "cp "$1"/*.txt ../searches/vhww/"$1"/"}' | /bin/sh
ls -d */ | awk '{print "cp "$1"/shapes/*.root ../searches/vhww/"$1"/shapes/"}' | /bin/sh





