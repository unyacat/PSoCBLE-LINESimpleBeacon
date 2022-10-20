# PSoCBLE-LINESimpleBeacon
PSoC BLE で LINE Simple Beacon を飛ばして入室を検知します．

![image](https://user-images.githubusercontent.com/14951631/119604700-7ec9f280-be2a-11eb-8949-e86e60898f64.png)


### 要件

+ LINE Business ID (無料 / LINEアカウントで誰でも取得可能)
+ PSoC BLE (手元で試したのは CYBLE-022001-00)





## 概要・設定

### 前提

LINEのビジネスアカウントを持っているものとします．なければ作ります．
https://developers.line.biz/console/

### Peripheral

[https://github.com/cypresssemiconductorco/PSoC-4-BLE/tree/master/100_Projects_in_100_Days/Day009_Dynamic_Broadcaster](https://github.com/cypresssemiconductorco/PSoC-4-BLE/tree/master/100_Projects_in_100_Days/Day009_Dynamic_Broadcaster) を元にパケットを改造して LINE Simple Beacon を飛ばしています．main.c の 233行目あたりです．

245行目から249行目を取得してきた HWID に変更します．
https://github.com/unyacat/PSoCBLE-LINESimpleBeacon/blob/main/Peripheral/Dynamic%20Broadcaster.cydsn/main.c#L244-L249

HWIDは[ここ](https://manager.line.biz/beacon/register)から発行できます．

仕様: [https://github.com/line/line-simple-beacon/blob/master/README.ja.md](https://github.com/line/line-simple-beacon/blob/master/README.ja.md) 



### Server

[https://github.com/line/line-bot-sdk-python](https://github.com/line/line-bot-sdk-python) の README.md にあるコードを元に Beacon 受信イベントを受け取ったときの処理を追加している Flask サーバーです．

取得してきた値に YOUR_CHANNEL_ACCESS_TOKEN と YOUR_CHANNEL_SECRET を変更します．  
Channel access token は Messaging API から，Channel Secret は Basic Settings から入手します．

Heroku に Deploy して MessagingAPI > Use webhook から URL を LINE に登録しておきます．

```Python3
@handler.add(BeaconEvent)
def handle_beacon(event):
    profile = line_bot_api.get_profile(user_id=event.source.user_id)
    line_bot_api.broadcast(
        TextSendMessage(text=profile.display_name + "の入室を確認しました！"))

```

