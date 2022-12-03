#include <iostream>
//#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#include <boost/asio.hpp>
//#undef BOOST_NO_CXX11_SCOPED_ENUMS


using namespace std;
using namespace boost::filesystem;
using namespace boost::asio;

int main()
{
    ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8001);
    path p{"/home/fx0"};
    try {
        file_status s = status(p);
        std::cout << std::boolalpha << is_directory(s) << '\n';
    } catch (filesystem_error &e) {
        std::cerr << e.what() << '\n';
    }

    cout << "Hello World!" << endl;
    return 0;
}
