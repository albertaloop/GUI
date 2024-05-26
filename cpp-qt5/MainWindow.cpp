#include "MainWindow.h"
#include "SocketComms.h"

MainWindow::MainWindow(CircularBuffer * sendBuffer,
                       CircularBuffer * responseBuffer,
                       QWidget* parent)
  : QMainWindow(parent)
{
  this->sendBuffer = sendBuffer;
  this->responseBuffer = responseBuffer;

  // Build layouts
  topVLayout = new QVBoxLayout;
  podNetHLayout = new QHBoxLayout;
  btnHLayout = new QHBoxLayout;
  brakeMotorBtnVLayout = new QVBoxLayout;
  brakeBtnHLayout = new QHBoxLayout;
  motorBtnHLayout = new QHBoxLayout;
  ledBtnVLayout = new QVBoxLayout;
  QSpacerItem * btnVSpacer = new QSpacerItem(20, 40, QSizePolicy::Fixed, QSizePolicy::Expanding);
  QSpacerItem * podNetLeftHSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Fixed);
  QSpacerItem * podNetRightHSpacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Fixed);
  QSpacerItem * podNetVSpacer = new QSpacerItem(20, 40, QSizePolicy::Fixed, QSizePolicy::Expanding);


  QWidget *widget = new QWidget(this);
  widget->setLayout(topVLayout);
  setCentralWidget(widget);

  
  podNetWidget = new PodNetWidget(this);

  topVLayout->addItem(podNetVSpacer);
  topVLayout->addLayout(podNetHLayout);
  topVLayout->addItem(btnVSpacer);
  topVLayout->addLayout(btnHLayout);
  podNetHLayout->addItem(podNetLeftHSpacer);
  podNetHLayout->addWidget(podNetWidget);
  podNetHLayout->addItem(podNetRightHSpacer);
  brakeMotorBtnVLayout->addLayout(motorBtnHLayout);
  brakeMotorBtnVLayout->addLayout(brakeBtnHLayout);
  btnHLayout->addLayout(brakeMotorBtnVLayout);
  btnHLayout->addLayout(ledBtnVLayout);

  // Construct command buttons
  motorForwardBtn = new QPushButton(this);
  motorStopBtn = new QPushButton;
  motorReverseOnBtn = new QPushButton;
  motorReverseOffBtn = new QPushButton;

  brakeEstopBtn = new QPushButton;
  brakePrepareBtn = new QPushButton;
  brakeReleaseBtn = new QPushButton;
  brakeEngageBtn = new QPushButton;

  ledNormalBtn = new QPushButton;
  ledFaultBtn = new QPushButton;

  connect(motorForwardBtn, &QPushButton::clicked, [sendBuffer]() { 
    sendBuffer->push(FORWARD);
  });
  connect(motorStopBtn, &QPushButton::clicked, [sendBuffer]() { 
    sendBuffer->push(STOP);
  });
  connect(motorReverseOnBtn, &QPushButton::clicked, [sendBuffer]() { 
    sendBuffer->push(REVERSE_ON);
  });
  connect(motorReverseOffBtn, &QPushButton::clicked, [sendBuffer]() { 
    sendBuffer->push(REVERSE_OFF);
  });

  connect(brakeEstopBtn, &QPushButton::clicked, [sendBuffer]() { 
    sendBuffer->push(BRAKE_ESTOP);
  });
  connect(brakePrepareBtn, &QPushButton::clicked, [sendBuffer]() { 
    sendBuffer->push(BRAKE_PREP_LAUNCH);
  });
  connect(brakeReleaseBtn, &QPushButton::clicked, [sendBuffer]() { 
    sendBuffer->push(BRAKE_LAUNCH);
  });
  connect(brakeEngageBtn, &QPushButton::clicked, [sendBuffer]() { 
    sendBuffer->push(BRAKE_CRAWL);
  });

  connect(ledNormalBtn, &QPushButton::clicked, [sendBuffer]() { 
    sendBuffer->push(LED_NORMAL);
  });
  connect(ledFaultBtn, &QPushButton::clicked, [sendBuffer]() { 
    sendBuffer->push(LED_FAULT);
  });



  btnHLayout->setStretch(0, 1);
  btnHLayout->setStretch(1, 0);
  btnHLayout->setStretch(2, 0);

  // Add buttons to layouts
  motorBtnHLayout->addWidget(motorForwardBtn);
  motorBtnHLayout->addWidget(motorStopBtn);
  motorBtnHLayout->addWidget(motorReverseOnBtn);
  motorBtnHLayout->addWidget(motorReverseOffBtn);

  brakeBtnHLayout->addWidget(brakeEstopBtn);
  brakeBtnHLayout->addWidget(brakePrepareBtn);
  brakeBtnHLayout->addWidget(brakeReleaseBtn);
  brakeBtnHLayout->addWidget(brakeEngageBtn);

  ledBtnVLayout->addWidget(ledNormalBtn);
  ledBtnVLayout->addWidget(ledFaultBtn);

  // Configure buttons
  motorForwardBtn->setText("Motor Forward");
  motorStopBtn->setText("Motor Stop");
  motorReverseOnBtn->setText("Motor Reverse On");
  motorReverseOffBtn->setText("Motor Reverse Off");

  brakeEstopBtn->setText("Brake EStop");
  brakePrepareBtn->setText("Brake Prepare Launch");
  brakeReleaseBtn->setText("Brake Release");
  brakeEngageBtn->setText("Brake Engage");

  ledNormalBtn->setText("LED Normal");
  ledFaultBtn->setText("LED Fault");

  motorForwardBtn->setFixedSize(200,100);
  motorStopBtn->setFixedSize(200,100);
  motorReverseOnBtn->setFixedSize(200,100);
  motorReverseOffBtn->setFixedSize(200,100);
  brakeEstopBtn->setFixedSize(200,100);
  brakePrepareBtn->setFixedSize(200,100);
  brakeReleaseBtn->setFixedSize(200,100);
  brakeEngageBtn->setFixedSize(200,100);
  ledNormalBtn->setFixedSize(200,100);
  ledFaultBtn->setFixedSize(200,100);

  motorForwardBtn->setStyleSheet("QPushButton { background-color: lightblue }");
  motorStopBtn->setStyleSheet("QPushButton { background-color: lightblue }");
  motorReverseOnBtn->setStyleSheet("QPushButton { background-color: lightblue }");
  motorReverseOffBtn->setStyleSheet("QPushButton { background-color: lightblue }");
  brakeEstopBtn->setStyleSheet("QPushButton { background-color: orange }");
  brakePrepareBtn->setStyleSheet("QPushButton { background-color: orange }");
  brakeReleaseBtn->setStyleSheet("QPushButton { background-color: orange }");
  brakeEngageBtn->setStyleSheet("QPushButton { background-color: orange }");
  ledNormalBtn->setStyleSheet("QPushButton { background-color: lightgreen }");
  ledFaultBtn->setStyleSheet("QPushButton { background-color: lightgreen }");


}

QSize MainWindow::sizeHint() const
{
  return QSize(1000,600);
}

QSize MainWindow::minimumSizeHint() const
{
  return QSize(1000,600);
}
