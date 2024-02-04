#ifndef SSVG_HPP
#define SSVG_HPP 1

#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
#include <sstream>
#include <fstream>

#include <string>

namespace bfs = boost::filesystem;

using namespace std;

namespace Snail
{

    class SSvg
    {
        public:
        SSvg()
        {

        }
        ~SSvg()
        {
            
        }

        static SSvg* __parseXmlDoc(const boost::property_tree::ptree& pt)
        {
            SSvg* tr = new SSvg();
            return tr;
        }

        static SSvg* LoadString(const string& contents)
        {
            stringstream ss;
            ss << contents;
            boost::property_tree::ptree pt;
            boost::property_tree::read_xml(ss, pt);

            return __parseXmlDoc(pt);
        }

        static SSvg* LoadPath(const boost::filesystem::path& path)
        {
            fstream fi;
            fi.open(path.string(), ios::in);
            boost::property_tree::ptree pt;
            boost::property_tree::read_xml(fi, pt);
            fi.close();
            return __parseXmlDoc(pt);
        }
    };
}

#endif