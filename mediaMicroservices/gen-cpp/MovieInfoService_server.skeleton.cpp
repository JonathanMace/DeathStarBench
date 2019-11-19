// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "MovieInfoService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::media_service;

class MovieInfoServiceHandler : virtual public MovieInfoServiceIf {
 public:
  MovieInfoServiceHandler() {
    // Your initialization goes here
  }

  void WriteMovieInfo(BaseRpcResponse& _return, const int64_t req_id, const std::string& movie_id, const std::string& title, const std::vector<Cast> & casts, const int64_t plot_id, const std::vector<std::string> & thumbnail_ids, const std::vector<std::string> & photo_ids, const std::vector<std::string> & video_ids, const std::string& avg_rating, const int32_t num_rating, const std::map<std::string, std::string> & carrier) {
    // Your implementation goes here
    printf("WriteMovieInfo\n");
  }

  void ReadMovieInfo(MovieInfoRpcResponse& _return, const int64_t req_id, const std::string& movie_id, const std::map<std::string, std::string> & carrier) {
    // Your implementation goes here
    printf("ReadMovieInfo\n");
  }

  void UpdateRating(BaseRpcResponse& _return, const int64_t req_id, const std::string& movie_id, const int32_t sum_uncommitted_rating, const int32_t num_uncommitted_rating, const std::map<std::string, std::string> & carrier) {
    // Your implementation goes here
    printf("UpdateRating\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<MovieInfoServiceHandler> handler(new MovieInfoServiceHandler());
  ::std::shared_ptr<TProcessor> processor(new MovieInfoServiceProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

