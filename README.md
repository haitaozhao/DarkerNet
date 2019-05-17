## Required
1. [OpenCV(3.4.6)](https://github.com/opencv/opencv/releases)
    ``` shell
    sudo apt-get -y install libopencv-dev build-essential cmake git libgtk2.0-dev pkg-config python-dev python-numpy libdc1394-22 libdc1394-22-dev libjpeg-dev libpng12-dev libtiff5-dev libjasper-dev libavcodec-dev libavformat-dev libswscale-dev libxine2-dev libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev libv4l-dev libtbb-dev libqt4-dev libfaac-dev libmp3lame-dev libopencore-amrnb-dev libopencore-amrwb-dev libtheora-dev libvorbis-dev libxvidcore-dev x264v4l-utils unzip libgl1-mesa-dev libglu1-mesa-dev libglut3-dev libgtkglext1 libgtkglext1-dev

    tar -zxvf opencv-3.4.6.tar.gz
    cd opencv-3.4.6
    mkdir build && cd build
    cmake ../ -DCMAKE_BUILD_TYPE=RELEASE \
        -DINSTALL_C_EXAMPLES=ON \
        -DCMAKE_INSTALL_PREFIX=/usr/local \
        -DWITH_TBB=ON \
        -DWITH_EIGEN=ON \
        -DWITH_CUDA=ON \
        -DWITH_CUBLAS=ON \
        -DCUDA_NVCC_FLAGS="-D_FORCE_INLINES" \
        -DBUILD_TIFF=ON \
        -DWITH_TIFF=ON \
        -DWITH_GDAL=ON \
        -DWITH_LIBV4L=ON \
        -DWITH_OPENGL=ON \
        -DWITH_GTK_2_X=ON
    make
    sudo make install
    ```

2. [OpenBLAS](http://www.openblas.net/)
    ``` shell
    git clone https://github.com/xianyi/OpenBLAS.git
    cd OpenBLAS
    make
    sudo make PREFIX=/usr/local/OpenBLAS install
    sudo echo "# >>> openblas >>>" >> ~/.bashrc
    sudo echo "export LD_LIBRARY_PATH=/usr/local/OpenBLAS/lib:$LD_LIBRARY_PATH" >> ~/.bashrc
    sudo echo "# <<< openblas <<<" >> ~/.bashrc
    sudo source ~/.bashrc
    ```

3. CUDA(9.0)
    注意`Ubuntu 18.04`安装`CUDA9.0`时，需要将`gcc`和`g++`版本回退
    ``` shell
    sudo apt-get install gcc-6
    sudo apt-get install g++-6
    sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 10
    sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 10
    ```

    安装
    ```
    sudo bash cuda_9.0.176_384.81_linux.run
    ```

    CUDA测试
    ``` shell
    nvcc -V
    nvcc: NVIDIA (R) Cuda compiler driver
    Copyright (c) 2005-2017 NVIDIA Corporation
    Built on Fri_Sep__1_21:08:03_CDT_2017
    Cuda compilation tools, release 9.0, V9.0.176

    cd ~/NVIDIA_CUDA-9.0_Samples/0_Simple/matrixMul
    make
    "/usr/local/cuda-9.0"/bin/nvcc -ccbin g++ -I../../common/inc  -m64    -gencode arch=compute_30,code=sm_30 -gencode arch=compute_35,code=sm_35 -gencode arch=compute_37,code=sm_37 -gencode arch=compute_50,code=sm_50 -gencode arch=compute_52,code=sm_52 -gencode arch=compute_60,code=sm_60 -gencode arch=compute_70,code=sm_70 -gencode arch=compute_70,code=compute_70 -o matrixMul.o -c matrixMul.cu
    "/usr/local/cuda-9.0"/bin/nvcc -ccbin g++   -m64      -gencode arch=compute_30,code=sm_30 -gencode arch=compute_35,code=sm_35 -gencode arch=compute_37,code=sm_37 -gencode arch=compute_50,code=sm_50 -gencode arch=compute_52,code=sm_52 -gencode arch=compute_60,code=sm_60 -gencode arch=compute_70,code=sm_70 -gencode arch=compute_70,code=compute_70 -o matrixMul matrixMul.o 
    mkdir -p ../../bin/x86_64/linux/release
    cp matrixMul ../../bin/x86_64/linux/release
    
    ./matrixMul 
    [Matrix Multiply Using CUDA] - Starting...
    GPU Device 0: "GeForce GT 730M" with compute capability 3.5

    MatrixA(320,320), MatrixB(640,320)
    Computing result using CUDA Kernel...
    done
    Performance= 41.61 GFlop/s, Time= 3.150 msec, Size= 131072000 Ops, WorkgroupSize= 1024 threads/block
    Checking computed result for correctness: Result = PASS

    NOTE: The CUDA Samples are not meant for performance measurements. Results may vary when GPU Boost is enabled.
    ```

4. CUDNN()
    ``` shell
    tar -zxf cudnn-9.0-linux-x64-v7.5.1.10.tgz
    cd cuda
    sudo cp include/cudnn.h /usr/local/cuda-9.0/include/
    sudo cp lib64/libcudnn* /usr/local/cuda-9.0/lib64
    ```

## Updates

- 2019.05.06: add `resize_connected_layer`.
- 2019.05.10: add `prelu`.
- 2019.05.11: OpenBLAS supported.
- 2019.05.12: add `print_network_weights`, `layer_type_to_string`.
- 2019.05.13: CUDA supported; add `prelu_layer_kernel.cu`, `clip_cpu/gpu`.
- 2019.05.14: modify layer typedef, pull cuda output each layer
- 2019.05.15: `list_delete`, `list_bsort`, `free_current_node`
- 2019.05.16: `list_check`, `list_attr`, `copy_image`
