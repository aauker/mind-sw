source env.sh

if [ -d "$INSTALL_DIR" ]; then
  ### Take action if $DIR exists ###
  echo "Setting up MINDSW at $INSTALL_DIR"
  export PATH=$INSTALL_DIR/bin:$PATH
  export LD_LIBRARY_PATH=$INSTALL_DIR/lib:$LD_LIBRARY_PATH
  export LIBRARY_PATH=$INSTALL_DIR/lib:$LIBRARY_PATH
  export C_INCLUDE_PATH=$INSTALL_DIR/include:$C_INCLUDE_PATH
  export CPLUS_INCLUDE_PATH=$INSTALL_DIR/include:$C_INCLUDE_PATH
else
  ###  Control will jump here if $DIR does NOT exists ###
  echo "Error: ${INSTALL_DIR} not found"
fi


