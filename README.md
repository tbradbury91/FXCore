# FXCore: Low-Latency FX Market Data Processing Engine

FXCore is a lightweight, high-performance C++ engine designed for ingesting and processing live FX market data via UDP multicast. It provides the foundational components for building low-latency FX trading systems, including efficient message parsing and order book management.

## Why FXCore?

FXCore focuses on the core challenges of FX trading infrastructure — reliably receiving and decoding high-throughput market data feeds with minimal latency. Handling UDP multicast streams and maintaining accurate order books are essential skills for quant developers working in FX and electronic trading.

## Tech Stack

- C++17  
- UDP Multicast for real-time market data ingestion  
- Efficient message parsing and order book construction  
- Cross-platform build system using CMake

## Features

- High-throughput UDP multicast listener optimized for FX data
- Parsing and decoding of market data messages
- Real-time order book updates with minimal delay
- Modular design allowing easy extension and integration

## Performance

- Handles thousands of messages per second with low CPU overhead
- Optimized for sub-millisecond latency processing
- Lightweight memory footprint

## How to Build and Run

```bash
git clone https://github.com/tbradbury91/FXCore.git
cd FXCore
mkdir build && cd build
cmake ..
make
./fxcore --config ../config.json
