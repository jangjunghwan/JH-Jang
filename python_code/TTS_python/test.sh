curl -v -X POST "https://kakaoi-newtone-openapi.kakao.com/v1/synthesize" \
-H "Content-Type: application/xml" \
-H "Authorization: KakaoAK 9408c07df55ac8b12b740941bb8f005b" \
-d '<speak>
이날 질병관리본부에 따르면 0시 기준으로 국내 코로나19 확진자는 전일 대비 74명이 늘어난 8236명으로 집계됐다.
<voice name="MAN_DIALOG_BRIGHT">특수문자!hello world.</voice>
<voice name="WOMAN_DIALOG_BRIGH" speechStyle="SS_ALT_FAST_1">금요일이 좋아요.</voice>
</speak>' > result.mp3