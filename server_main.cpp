#include <iostream>
#include "httplib.h"

// https://github.com/yhirose/cpp-httplib



std::string dump_headers(const httplib::Headers &headers) {
  std::string s;
  char buf[BUFSIZ];

  for (auto it = headers.begin(); it != headers.end(); ++it) {
    const auto &x = *it;
    snprintf(buf, sizeof(buf), "%s: %s\n", x.first.c_str(), x.second.c_str());
    s += buf;
  }

  return s;
}
auto main() -> int
{
    httplib::Server svr;
    svr.Get("/hi", [](const httplib::Request &req, httplib::Response &res)
            { 
               
                res.set_content(dump_headers(req.headers), "text/plain"); 
            });
    
    svr.Get(R"(/numbers/(\d+))", [&](const httplib::Request &req, httplib::Response &res)
            {
                auto numbers = req.matches[1];
                res.set_content(numbers, "text/plain"); 
                });

    svr.Get("/body-header-param", [](const httplib::Request &req, httplib::Response &res)
            {
                if (req.has_header("Content-Length")) {
                    auto val = req.get_header_value("Content-Length");
                    
                    }
    
                    if (req.has_param("key")) {
                        auto val = req.get_param_value("key");
                        res.set_content(val, "text/plain"); 
                    } else
                    res.set_content(req.body, "text/plain"); 
            });

    svr.Get("/stop", [&](const httplib::Request &req, httplib::Response &res)
            { 
                svr.stop(); 
            });
    std::cout << "starting server .." << std::endl;
    svr.listen("0.0.0.0", 8080);
    return 0;
}