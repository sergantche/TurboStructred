#!MC 1410
$!VarSet |MFBD| = 'C:\Program Files\Tecplot\Tecplot 360 EX 2015 R1'
$!PICK ADDATPOSITION
  X = 3.88975817923
  Y = 2.46906116643
  CONSIDERSTYLE = YES
$!READDATASET  '"D:\Dropbox\!Sega\GitHub\TurboStructred\TurboStructured\dataT1.00.dat" '
  READDATAOPTION = NEW
  RESETSTYLE = YES
  VARLOADMODE = BYNAME
  ASSIGNSTRANDIDS = YES
  VARNAMELIST = '"X" "Y" "Rho" "u" "v" "w" "P" "e"'
$!READDATASET  '"D:\Dropbox\!Sega\GitHub\TurboStructred\TurboStructured\ENO2\dataT1.000.dat" '
  READDATAOPTION = APPEND
  RESETSTYLE = NO
  VARLOADMODE = BYNAME
  ASSIGNSTRANDIDS = YES
  VARNAMELIST = '"X" "Y" "Rho" "u" "v" "w" "P" "e"'
$!SETCONTOURVAR 
  VAR = 3
  CONTOURGROUP = 1
  LEVELINITMODE = RESETTONICE
$!ACTIVEFIELDMAPS -= [1]
$!GLOBALRGB REDCHANNELVAR = 3
$!GLOBALRGB GREENCHANNELVAR = 3
$!GLOBALRGB BLUECHANNELVAR = 3
$!SETCONTOURVAR 
  VAR = 7
  CONTOURGROUP = 2
  LEVELINITMODE = RESETTONICE
$!SETCONTOURVAR 
  VAR = 8
  CONTOURGROUP = 3
  LEVELINITMODE = RESETTONICE
$!SETCONTOURVAR 
  VAR = 3
  CONTOURGROUP = 4
  LEVELINITMODE = RESETTONICE
$!SETCONTOURVAR 
  VAR = 3
  CONTOURGROUP = 5
  LEVELINITMODE = RESETTONICE
$!SETCONTOURVAR 
  VAR = 3
  CONTOURGROUP = 6
  LEVELINITMODE = RESETTONICE
$!SETCONTOURVAR 
  VAR = 3
  CONTOURGROUP = 7
  LEVELINITMODE = RESETTONICE
$!SETCONTOURVAR 
  VAR = 3
  CONTOURGROUP = 8
  LEVELINITMODE = RESETTONICE
$!FIELDLAYERS SHOWCONTOUR = YES
$!PICK ADDATPOSITION
  X = 5.10739687055
  Y = 5.6326458037
  CONSIDERSTYLE = YES
$!VIEW FIT
$!PICK SETMOUSEMODE
  MOUSEMODE = SELECT
$!ATTACHGEOM 
  ANCHORPOS
    {
    X = 0.2975470585111427
    Y = -0.003368757894737007
    }
  RAWDATA
1
2
0 0 
0 0.114315204322 
$!PICK ADDATPOSITION
  X = 5.50568990043
  Y = 6.80476529161
  CONSIDERSTYLE = YES
$!ACTIVEFIELDMAPS += [1]
$!PICK ADDATPOSITION
  X = 5.49431009957
  Y = 6.73648648649
  COLLECTINGOBJECTSMODE = ALWAYSADD
  CONSIDERSTYLE = YES
$!EXTRACTFROMGEOM 
  EXTRACTLINEPOINTSONLY = NO
  INCLUDEDISTANCEVAR = NO
  NUMPTS = 200
  EXTRACTTOFILE = NO
$!PLOTTYPE = XYLINE
$!DELETELINEMAPS 
$!PICK ADDATPOSITION
  X = 4.61806543385
  Y = 7.02098150782
  CONSIDERSTYLE = YES
$!PICK ADDATPOSITION
  X = 3.90113798009
  Y = 6.58854907539
  CONSIDERSTYLE = YES
$!PLOTTYPE = CARTESIAN2D
$!ACTIVEFIELDMAPS -= [3]
$!ACTIVEFIELDMAPS -= [2]
$!ACTIVEFIELDMAPS += [2]
$!ACTIVEFIELDMAPS -= [1]
$!ACTIVEFIELDMAPS += [1]
$!ACTIVEFIELDMAPS -= [2]
$!ACTIVEFIELDMAPS += [2]
$!ACTIVEFIELDMAPS -= [1]
$!ACTIVEFIELDMAPS -= [2]
$!PICK ADDATPOSITION
  X = 5.46017069701
  Y = 5.40504978663
  CONSIDERSTYLE = YES
$!VIEW FIT
$!ACTIVEFIELDMAPS += [2]
$!PICK ADDATPOSITION
  X = 5.38051209104
  Y = 5.06365576102
  CONSIDERSTYLE = YES
$!VIEW FIT
$!ACTIVEFIELDMAPS -= [2]
$!ACTIVEFIELDMAPS += [1]
$!PICK ADDATPOSITION
  X = 5.52844950213
  Y = 5.59850640114
  CONSIDERSTYLE = YES
$!VIEW FIT
$!PICK ADDATPOSITION
  X = 5.49431009957
  Y = 6.6113086771
  CONSIDERSTYLE = YES
$!PICK ADDATPOSITION
  X = 5.49431009957
  Y = 6.6113086771
  COLLECTINGOBJECTSMODE = ALWAYSADD
  CONSIDERSTYLE = YES
$!EXTRACTFROMGEOM 
  EXTRACTLINEPOINTSONLY = NO
  INCLUDEDISTANCEVAR = NO
  NUMPTS = 200
  EXTRACTTOFILE = NO
$!PLOTTYPE = XYLINE
$!CREATELINEMAP 
$!LINEMAP [1]  NAME = 'Map 0'
$!LINEMAP [1]  ASSIGN{XAXISVAR = 2}
$!LINEMAP [1]  ASSIGN{YAXISVAR = 4}
$!LINEMAP [1]  ASSIGN{ZONE = 3}
$!ACTIVELINEMAPS += [1]
$!VIEW FIT
$!CREATELINEMAP 
$!LINEMAP [2]  NAME = 'Map 1'
$!LINEMAP [2]  ASSIGN{XAXISVAR = 2}
$!LINEMAP [2]  ASSIGN{YAXISVAR = 4}
$!LINEMAP [2]  ASSIGN{ZONE = 4}
$!ACTIVELINEMAPS += [2]
$!PICK ADDATPOSITION
  X = 3.11593172119
  Y = 5.88300142248
  CONSIDERSTYLE = YES
$!VIEW FIT
$!VIEW ZOOM
  X1 = -0.00136451400962
  Y1 = -5.95279678355E-005
  X2 = 0.101944938489
  Y2 = 0.0187357153949
$!RemoveVar |MFBD|
