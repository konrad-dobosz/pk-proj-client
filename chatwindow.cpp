#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::on_pushButton_clicked()
{
    QString message = ui->plainTextEdit->toPlainText();

    if (!message.isEmpty())
    {
        SocketMessage msg;

        emit sendMessage(msg);

        QDateTime date;
        date = date.currentDateTime();

        QString username = "Ty";
        appendMessage(username, message);
    }
    else
    {
        qDebug() << "Wiadomość jest pusta!";
    }
}

void ChatWindow::appendMessage(QString &username, QString &message) {
    QDateTime date;
    date = date.currentDateTime();

    ui->textBrowser->append(username + ": " + message + "<br>[" + date.toString() + "]<br>");
}