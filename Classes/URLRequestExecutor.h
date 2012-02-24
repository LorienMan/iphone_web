//
//  This content is released under the MIT License: http://www.opensource.org/licenses/mit-license.html
//

#import <Foundation/Foundation.h>

@protocol RequestExecutorDelegate;


@interface URLRequestExecutor : NSObject
@property (nonatomic, unsafe_unretained) id<RequestExecutorDelegate> delegate;
@property (nonatomic, strong, readonly) NSURLRequest* originalRequest;
@property (nonatomic, strong, readonly) NSURLRequest* currentRequest;
@property (nonatomic, strong, readonly) NSURLResponse* response;
@property (nonatomic, strong, readonly) NSError* error;

- (id)initWithRequest:(NSURLRequest*)req;

- (void)start;
- (void)cancel;

@end


@protocol RequestExecutorDelegate <NSObject>
@optional

- (void)requestExecutor:(URLRequestExecutor*)executor didFinishWithResponse:(NSURLResponse*)response;

- (void)requestExecutor:(URLRequestExecutor*)executor didFinishWithData:(NSData*)data;

- (void)requestExecutor:(URLRequestExecutor*)executor didFailWithError:(NSError*)error;

- (void)requestExecutor:(URLRequestExecutor*)executor didReceiveResponse:(NSURLResponse*)response;

- (void)requestExecutor:(URLRequestExecutor*)executor didReceiveDataChunk:(NSData*)data;

- (NSURLRequest*)requestExecutor:(URLRequestExecutor*)executor didReceiveRedirectResponse:(NSURLResponse*)response willSendRequest:(NSURLRequest*)request;

@end