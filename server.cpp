#include <httplib.h>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
std::string s_status = "WORK";
json jGet;

int main(void) {

  using namespace httplib;
  jGet["status"] = s_status;
  json jPost = {"coords", {
			{"x", 0}, {"y", 0}, {"z", 0}}, 
		   {"picture", ""},
		   {"speed", 0}, 
		   {"speedSearch", 0},
		   {"type", ""}};
    Server svr;
// std::cout << jPost << std::endl;
  svr.Get("/hi", [](const Request& req, Response& res) {
    res.set_content("Hello World!", "text/plain");
  });

  svr.Get("/stop", [&](const Request& req, Response& res) {
    svr.stop();
  });

  svr.Get("/status", [&](const Request & req, Response &res) {
        res.set_content(jGet.dump(), "application/json");
	  std::cout << jGet["status"] << std::endl;
  });

  svr.Post("/post_coords", [&](const Request& req, Response& res) {
        jPost = json::parse(req.body);
        std::cout << "Post = " << jPost << std::endl;

    });


  svr.listen("192.168.133.141", 8080);
}
