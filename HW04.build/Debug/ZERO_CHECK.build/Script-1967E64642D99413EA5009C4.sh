#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/brianxu/Documents/GitHub/hw04-xujbrian
  make -f /Users/brianxu/Documents/GitHub/hw04-xujbrian/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/brianxu/Documents/GitHub/hw04-xujbrian
  make -f /Users/brianxu/Documents/GitHub/hw04-xujbrian/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/brianxu/Documents/GitHub/hw04-xujbrian
  make -f /Users/brianxu/Documents/GitHub/hw04-xujbrian/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/brianxu/Documents/GitHub/hw04-xujbrian
  make -f /Users/brianxu/Documents/GitHub/hw04-xujbrian/CMakeScripts/ReRunCMake.make
fi

