if [ "$#" -ne 3 ]; then
  echo "wrong param number, found $# expected 3"
  exit 1
fi
declare -a arr=("A" "B" "C" "D" "E")

if [ ! -d ${1} ]; then
  mkdir ${1}
fi

if [ ! -d "${1}/${2}" ]; then
  mkdir "${1}/${2}"
fi

if [ ! -d "${1}/${2}/${3}" ]; then
  mkdir "${1}/${2}/${3}"
fi


FILENAME="debug_lib.cpp"
if [ -f ${FILENAME} ] ; then
  cp $FILENAME "${1}/${2}/${3}/${FILENAME}"
fi

for i in ${arr[@]}; do
  FILENAME=${1}/${2}/${3}/Problem${i}.cpp
  if [ -f ${FILENAME} ] ; then
    echo "Error: ${FILENAME} already exists. Skipping"
  else
    cp "Template.cpp" ${FILENAME}
  fi
done
