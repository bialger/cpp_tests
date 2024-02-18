#!/bin/sh

OS_NAME="$(cmake -P ./PrintOS.cmake 2>&1)"
PROJECT_NAME="cpp_tests"
CMAKE_BUILD_DIR="$HOME/CMakeBuilds"
CMAKE_PROJECT_DIR="$CMAKE_BUILD_DIR/$PROJECT_NAME"

if [ -e "$CMAKE_PROJECT_DIR" ]; then
  rm -rf "$CMAKE_PROJECT_DIR"
fi

EXEC_EXTENSION=".exe"
EXEC_PATH="$CMAKE_PROJECT_DIR/Debug/$PROJECT_NAME$EXEC_EXTENSION"

if [ "$OS_NAME" = "Linux" ]; then
  EXEC_EXTENSION=".run"
  EXEC_PATH="$CMAKE_PROJECT_DIR/bin/$PROJECT_NAME"
elif [ "$OS_NAME" = "MacOS" ]; then
  EXEC_EXTENSION=".run"
  EXEC_PATH="$CMAKE_PROJECT_DIR/bin/$PROJECT_NAME"
fi

EXEC_LINK_PATH="$HOME/$PROJECT_NAME$EXEC_EXTENSION"

if (cmake -S . -B "$CMAKE_PROJECT_DIR" -DCMAKE_BUILD_TYPE=Release && cmake --build "$CMAKE_PROJECT_DIR" --target "$PROJECT_NAME"); then
  rm -f "$EXEC_LINK_PATH"
  ln -s "$EXEC_PATH" "$EXEC_LINK_PATH"
  echo ''

  if ("$EXEC_LINK_PATH" -h >/dev/null 2>/dev/null); then
    echo "Congratulations! $PROJECT_NAME was compiled successfully."
    echo ''
    "$EXEC_LINK_PATH" -h
    echo ''

    if [ "$OS_NAME" = "Linux" ]; then
      printf 'Do you want to add this utility to /usr/bin (y/n)? ' && read -r CHOISE
      COMMON_LINK_PATH="/usr/bin/${PROJECT_NAME:?}"
      COMMON_PROJECT_DIR="/opt/${PROJECT_NAME:?}"
      COMMON_EXEC_PATH="$COMMON_PROJECT_DIR/bin/$PROJECT_NAME"

      if [ "$CHOISE" = "y" ]; then
        sudo rm -f "$COMMON_LINK_PATH"

        if (sudo ln -s "$EXEC_PATH" "$COMMON_LINK_PATH"); then
          if [ -e "$COMMON_PROJECT_DIR" ]; then
            sudo rm -rf "$COMMON_PROJECT_DIR"
          fi

          sudo rm -f "$COMMON_LINK_PATH"
          sudo cp -r "$CMAKE_PROJECT_DIR" "$COMMON_PROJECT_DIR"
          sudo ln -s "$COMMON_EXEC_PATH" "$COMMON_LINK_PATH"
          echo "Accepted, run utility with $PROJECT_NAME"
        else
          echo 'Please try again later.'
          echo "Declined, run utility with $EXEC_LINK_PATH"
        fi
      else
        echo "Declined, run utility with $EXEC_LINK_PATH"
      fi
    else
      echo "Run utility with $EXEC_LINK_PATH"
    fi

    exit 0
  else024d1f50-bba3-4e7f-a124-32ab0f76a567
    echo 'Oops! Could not execute the program.'
    exit 1
  fi
else
  echo 'Error occurred during running CMake. Make sure that it is installed and configured properly.'
  exit 1
fi
