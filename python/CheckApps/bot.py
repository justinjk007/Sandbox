import secret
import telebot
import check_apps

bot = telebot.TeleBot(secret.BOT_TOKEN)

@bot.message_handler(commands=['start', 'hello'])
def send_welcome(message):
    bot.reply_to(message, "Howdy, how are you doing?")

@bot.message_handler(commands=['check'])
def check_appointment(message):
    data = check_apps.check()
    reply = f'Results: {data}!'
    bot.reply_to(message, reply)

bot.infinity_polling()
