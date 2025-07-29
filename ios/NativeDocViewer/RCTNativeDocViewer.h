//
//  RCTNativeDocViewer.h
//  AwesomeProject
//
//  Created by 闫瑞锋 on 2025/7/29.
//

#import <Foundation/Foundation.h>
#import <NativeDocViewerSpec/NativeDocViewerSpec.h>
#import <QuickLook/QuickLook.h>
#import <React/RCTEventEmitter.h>
#import <React/RCTBridgeModule.h>
#import <React/RCTLog.h>

NS_ASSUME_NONNULL_BEGIN

@interface RCTNativeDocViewer : RCTEventEmitter <NativeDocViewerSpec,  QLPreviewControllerDelegate,NSURLSessionDelegate, QLPreviewControllerDataSource, QLPreviewItem, UIAlertViewDelegate>

@property (strong, nonatomic) NSURL* fileUrl;
@property (strong, nonatomic) NSString* optionalFileName;
@property (readonly) NSURL* previewItemURL;
@property (strong, nonatomic) NSData* downloadResumeData;
@property (strong, nonatomic) UIAlertView* alert;
@property (strong, nonatomic) UIProgressView* downloadProgressView;

@end

NS_ASSUME_NONNULL_END
