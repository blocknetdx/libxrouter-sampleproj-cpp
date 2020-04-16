#include <xrouter/xrouterclient.h>
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[]) {
    // Create and start the xrouter client
    auto client = std::unique_ptr<xrouter::XRouterClient>(new xrouter::XRouterClient(xrouter::XRouterClient::defaultOptions()));
    if (!client->start()) {
        std::cout << "Failed to find service" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    // Wait up to 10 seconds for the service to be found
    if (!client->waitForService(10000, "xr::BLOCK")) {
        std::cout << "Failed to find service" << std::endl;
        client->stop();
        std::exit(EXIT_FAILURE);
    }
    // Get the block count for the xr::BLOCK SPV service
    auto res = client->getBlockCount("xr::BLOCK");
    std::cout << res.write(2) << std::endl;
    client->stop();
    client = nullptr;
    std::exit(EXIT_SUCCESS);
}