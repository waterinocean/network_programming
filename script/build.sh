
input_mode=Debug
input_compile=
echo $@

while [ -n "$1" ]
do
    case "$1" in
        -r|--release)
            input_mode=Release
            shift 1
            ;;
        -w|--windows)
            input_compile="Unix Makefiles"
            shift 1
            ;;
        *)
        echo "invalid para"
        exit 1
        ;;
    esac
done

if [ ! -d build ]; then
    mkdir build;
fi

cd build
if [ $input_compile != "" ]; then
    cmake .. -DCMAKE_BUILD_TYPE=$input_mode -G $input_compile
else
    cmake .. -DCMAKE_BUILD_TYPE=$input_mode
fi
cmake --build .

exit 0
