if [ "$#" -eq 0 ]; then
  year=$(date +%Y)
  month=$(date +%m)
  day=$(date +%d)
elif [ "$#" -ne 3 ]; then
  echo "Wrong number of parameters: found $#; expected 3 or 0."
  exit 1
else
  year=${1}
  month=${2}
  day=${3}
fi
declare -a arr=("A" "B" "C" "D" "E")


if [ ! -d ${year} ]; then
  mkdir ${year}
fi

if [ ! -d "${year}/${month}" ]; then
  mkdir "${year}/${month}"
fi

if [ ! -d "${year}/${month}/${day}" ]; then
  mkdir "${year}/${month}/${day}"
fi


FILENAME="debug_lib.cpp"
if [ -f ${FILENAME} ] ; then
  cp $FILENAME "${year}/${month}/${day}/${FILENAME}"
fi

for i in ${arr[@]}; do
  FILENAME=${year}/${month}/${day}/Problem${i}.cpp
  if [ -f ${FILENAME} ] ; then
    echo "Error: ${FILENAME} already exists. Skipping"
  else
    cp "Template.cpp" ${FILENAME}
  fi
done

FILENAME="${year}/${month}/${day}/test"
if [ ! -f ${FILENAME} ]; then
  touch ${FILENAME}
fi
