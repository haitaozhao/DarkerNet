# DarkerNet
Based on Darknet.

## Required
1. [OpenCV(3.4.6)](https://github.com/opencv/opencv/releases)
    ``` shell
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
        -DWITH_OPENGL=ON 
    make
    sudo make install
    ```

2. [OpenBLAS](http://www.openblas.net/)
    ``` shell
    git clone https://github.com/xianyi/OpenBLAS.git
    cd OpenBLAS
    make
    sudo make install   # /usr/local/OpenBLAS
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
    make && ./matrixMul 
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
- 2019.05.15: modify layer typedef, pull cuda output each layer
