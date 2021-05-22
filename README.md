# PSoCBLE-LINESimpleBeacon
PSoC BLE で LINE Simple Beacon を飛ばして入室を検知します．

要: LINE Business ID 





## 構成

### Peripheral

[https://github.com/cypresssemiconductorco/PSoC-4-BLE/tree/master/100_Projects_in_100_Days/Day009_Dynamic_Broadcaster]() を元にパケットを改造して LINE Simple Beacon を飛ばします．main.c の 233行目あたり．

仕様: [https://github.com/line/line-simple-beacon/blob/master/README.ja.md]() 



### Server

[https://github.com/line/line-bot-sdk-python]() の README.md にあるコードを元に Beacon 受信イベントを受け取ったときの処理を追加している Flask サーバー．

```Python3
@handler.add(BeaconEvent)
def handle_beacon(event):
    profile = line_bot_api.get_profile(user_id=event.source.user_id)
    line_bot_api.broadcast(
        TextSendMessage(text=profile.display_name + "の入室を確認しました！"))

```

