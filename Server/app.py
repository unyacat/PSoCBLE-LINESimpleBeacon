from flask import Flask, request, abort

from linebot import (
    LineBotApi, WebhookHandler
)
from linebot.exceptions import (
    InvalidSignatureError
)
from linebot.models import (
    MessageEvent, TextMessage, TextSendMessage, BeaconEvent
)

app = Flask(__name__)

# 各自取得した値に変更する
line_bot_api = LineBotApi('YOUR_CHANNEL_ACCESS_TOKEN')
handler = WebhookHandler('YOUR_CHANNEL_SECRET')

@app.route("/callback", methods=['POST'])
def callback():
    # get X-Line-Signature header value
    signature = request.headers['X-Line-Signature']

    # get request body as text
    body = request.get_data(as_text=True)
    app.logger.info("Request body: " + body)

    # handle webhook body
    try:
        handler.handle(body, signature)
    except InvalidSignatureError:
        print("Invalid signature. Please check your channel access token/channel secret.")
        abort(400)

    return 'OK'


@handler.add(MessageEvent, message=TextMessage)
def handle_message(event):
    profile = line_bot_api.get_profile(user_id=event.source.user_id)
    line_bot_api.broadcast(
        TextSendMessage(text=profile.display_name + ": " + event.message.text))


@handler.add(BeaconEvent)
def handle_beacon(event):
    profile = line_bot_api.get_profile(user_id=event.source.user_id)
    line_bot_api.broadcast(
        TextSendMessage(text=profile.display_name + "の入室を確認しました！"))


if __name__ == "__main__":
    app.run()