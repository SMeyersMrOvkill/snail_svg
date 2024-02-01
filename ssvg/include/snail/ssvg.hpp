#ifndef SSVG_HPP
#define SSVG_HPP 1

#include <snail/_check_json_data.hpp>

#include <boost/filesystem.hpp>
#include <boost/json.hpp>

#include <string>

namespace bfs = boost::filesystem;
namespace bjson = boost::json;

using namespace std;

namespace Snail
{

    class SSvg
    {
        public:
        SSvg();
        ~SSvg();

        static SSvg* loads(const string& contents)
        {
            bjson::value v = bjson::parse(contents);
            if(v.is_null())
            {
                return nullptr;
            }
            if(!__snail_check_json_data(v))
            {
                return nullptr;
            }
            SSvg* tr = new SSvg();
            
            return tr;
        }

        static SSvg* load(const boost::filesystem::path& path)
        {
            if(!bfs::exists(path))
            {
                return nullptr;
            }
            string contents;
            bfs::ifstream f(path);
            f >> contents;
            f.close();
            return SSvg::loads(contents);
        }
    };
}

#endif