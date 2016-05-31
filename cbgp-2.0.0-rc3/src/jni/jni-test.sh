#!/bin/bash
# ===================================================================
# C-BGP Java/JNI testing script.
# (c) 2007, Bruno Quoitin (bruno.quoitin@uclouvain.be)
# ===================================================================

# Classpath. Must include
# - CBGP jar file
# - junit jar file
# - user-defined CLASSPATH
CLASSPATH=../../src/jni/CBGP.jar:../../lib/junit-4.4.jar:$CLASSPATH

# List of temporary files (to be removed later)
CLEAN=""


# -------------------------------------------------------------------
# If we are on Darwin, JNI shared libraries must have the .jnilib
# extension. We make a temporary soft link for this purpose.
# -------------------------------------------------------------------
HOST_OS="linux-gnu"
echo ${HOST_OS:0:6}
if [ ${HOST_OS:0:6} = "darwin" ]; then
    JNILIB=../../src/.libs/libcsim.jnilib
    CLEAN="$CLEAN $JNILIB"
    ln -s ../../src/.libs/libcsim.dylib $JNILIB
fi


# -------------------------------------------------------------------
# Run the JUnit test with the CBGP AllTests class as target.
# -------------------------------------------------------------------
$SHELL ../../libtool --mode=execute  \
    -Djava.library.path=../../src/.libs \
    -classpath $CLASSPATH \
    org.junit.runner.JUnitCore be.ac.ucl.ingi.cbgp.testing.AllTests
EXIT_STATUS=$?


# -------------------------------------------------------------------
# Remove temporary files
# -------------------------------------------------------------------
if [ ! -z $CLEAN ]; then
    for f in $CLEAN; do
	rm -f $f
    done
fi


# -------------------------------------------------------------------
# Return test exit status
# -------------------------------------------------------------------
exit $EXIT_STATUS
