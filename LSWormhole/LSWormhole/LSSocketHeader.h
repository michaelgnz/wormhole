//
//  LSSocketHeader.h
//  LSWormhole
//  Created by xqwang on 2018/9/24.
//

#import <Foundation/Foundation.h>

//#define SERVER_HOST @"xxx.xxx.xxx.xxx"  //阿里云服务器
//#define SERVER_HOST @"192.168.1.8"   //家
//#define SERVER_HOST @"10.1.6.105"    //公司
//#define SERVER_HOST @"10.1.2.192"    //公司爱奇艺
#define SERVER_HOST @"xxx.xxx.xxx.xxx"    //公司爱奇艺
#define SERVER_PORT 22345
//#define SERVER_PORT 12345
#define LOCAL_SERVER_PORT 22346

#define PacketHeadSize          12

#define ID_HEART_BEAT_PACKAGE          0  //心跳包
#define ID_NORMAL_PACKAGE              1  //普通算法包
#define ID_COMMAND_PACKAGE             2  //命令包
#define ID_RESPONSE_PACKAGE            3  //信息反馈包
#define ID_IDENTIFY_PACKAGE            4  //身份识别包
#define ID_CLOSE_PACKAGE               5  //客户端释放连接包

#define SOCKET_OFFLINE_BY_SERVER    0
#define SOCKET_OFFLINE_BY_USER      1
#define SOCKET_OFFLINE_BY_NETWORK   2

//#define TARGET_APP_BUNDLE_ID  @"com.ss.iphone.ugc.Aweme"
#define TARGET_APP_BUNDLE_ID  @"com.qiyi.iphone"

// 包头
typedef struct tagNetPacketHead
{
    int version;                    //版本
    int type;                       //包体类型
    unsigned int nLen;              //包体长度
} NetPacketHead;

// 定义发包类型
typedef struct tagNetPacket
{
    NetPacketHead header;      //包头
    unsigned char *body;      //包体
} NetPacket;

//命令类运行结束后回调
typedef void(^CommandRunComplete)(BOOL succ, NSData* data);

@protocol LSSocketDelegate <NSObject>

//新的socket连接到当前服务器
@optional
-(void)socketDidConnect:(id)sock;

//接收到普通数据包
@optional
-(void)socket:(id)sock didReceiveNormalData:(NSData*)data;

//接收到命令包
@optional
-(void)socket:(id)sock didReceiveCommand:(NSData*)data;

//接收到反馈包
@optional
-(void)socket:(id)sock didReceiveResponse:(NSData*)data;

//socket丢失联结
@optional
-(void)socket:(id)sock didLostConnection:(NSError*)error;

@end

