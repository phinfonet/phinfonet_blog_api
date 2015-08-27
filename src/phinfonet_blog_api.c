#include <kore/kore.h>
#include <kore/http.h>
#include "assets.h"

int	blog_posts(struct http_request *);

int blog_posts(struct http_request *req) {
  if (req->method != HTTP_METHOD_GET) {
    http_response_header(req, "allow", "GET");
		http_response(req, 405, NULL, 0);
    return (KORE_RESULT_OK);
  }
  
	http_response_header(req, "content-type", "application/json");
	http_response(req, 200, asset_home_json, asset_len_home_json);
	kore_log(LOG_NOTICE, "GET BLOG POSTS");
	return (KORE_RESULT_OK);
}
