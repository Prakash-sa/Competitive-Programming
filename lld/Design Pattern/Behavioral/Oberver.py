# It's common for different components of an app to respond to events or state changes, 
# but how can we communicate these events?
# The Observer pattern is a popular solution. We have a Subject (aka Publisher) which will be the source of events.
#  And we could have multiple Observers (aka Subscribers) which will recieve events from the Subject in realtime.

## pub/sub

class YoutubeChannel:
    def __init__(self,name):
        self.name=name
        self.subscribers=[]

    def subscribe(self,sub):
        self.subscribes.append(sub)
    
    def notify(self,event):
        for sub in self.subscribers:
            sub.sendNotification(self.name,event)

from abc import ABC,abstractmethod


class YoutubeSubscriber(ABC):
    @abstractmethod
    def sendNotification(self,event):
        pass

class YoutubeUser(YoutubeSubscriber):
    def __init__(self,name):
        self.name=name

    def sendNotification(self,channel,event):
        print(f"User {self.name} received notification from {channel}: {event}")

channel=YoutubeChannel("neetcode")

channel.subscribe(YoutubeUser("sub1"))
channel.subscribe(YoutubeUser("sub2"))
channel.subscribe(YoutubeUser("sub3"))
