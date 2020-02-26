# Dalio, Brian A.
# dalioba
# 2020-02-24
#-----------------------------------------------------------

import re
import sys

#-----------------------------------------------------------
def processToken( token ) :
  tent = re.compile('^\+\$*[0-7g-n]+\^$')
  aitchpi = re.compile('^[0-9a-fA-F]*\]\([q-zQ-Z]*$')
  juggle = re.compile('^\([N-Za-m]+\#$')

  if tent.match(token):
       print('>%s< matches Tent.' % ( token ) )
  elif aitchpi.match(token):
      print('>%s< matches AitchPi.' % ( token ) )
  elif juggle.match(token):
      print('>%s< matches Juggle.' % ( token ) )
  else:
      print('>%s< does not match.' % ( token ) )

#-----------------------------------------------------------
# DO NOT CHANGE anything below this line!
def main() :
  fName = sys.argv[ 1 ]
  print( 'processing tokens from ' + fName + ' ...' )

  with open( fName, 'r' ) as fp :
    lines = fp.read().replace( '\r', '' ).split( '\n' )

  for line in lines :
    for token in line.split() :
      processToken( token )

#-----------------------------------------------------------
# DO NOT CHANGE anything below this line!
if ( __name__ == '__main__' ) :
  main()

#-----------------------------------------------------------
