FROM gcc:latest

RUN apt-get update && \
    apt-get install -y cmake && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN cmake -S . -B build && cmake --build build

CMD ["ctest", "--test-dir", "build", "--output-on-failure"]
