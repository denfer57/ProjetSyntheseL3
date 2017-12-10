

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class TestServeurDessin
{

public static void main(String[] args)
{
int portServeurDessin = 8091;   // arbitraire. N'importe quel port libre convient
String adresseIP = "127.0.0.1";
try
    {
    ServerSocket serveurDessin = new ServerSocket(portServeurDessin, 1, InetAddress.getByName(adresseIP));

    System.out.println("serveur de dessin pr�t, \n d�tails : "+serveurDessin);

    int nombreClients;

    nombreClients = 0;

    while (true)
        {
        System.out.println("serveur de dessin en attente du prochain client");
        Socket socket = serveurDessin.accept();
        ++nombreClients;
        System.out.println("nouveau client connect� n� = " + nombreClients);
        SessionDessin sessionDessin = new SessionDessin(socket);                // interlocuteur prenant en charge la session de dessin du nouveau client,
        sessionDessin.start();                                                  // il travaille dans un thread s�par�, en parall�le de l'activit� de serveurDessin
        }
    }
catch (IOException e)
    {

    System.err.println("Le serveur n'a pu �tre connect� sur le port d'�coute ou la connexion sur ce port a �t� rompue. \n D�tails : "+e);
    }
}
}
