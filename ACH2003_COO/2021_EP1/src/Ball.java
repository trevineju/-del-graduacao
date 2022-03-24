import java.awt.*;
import java.lang.Math;

/**
	Esta classe representa a bola usada no jogo. A classe princial do jogo (Pong)
	instancia um objeto deste tipo quando a execução é iniciada.
*/

public class Ball {
	private double cx;
	private double cy;
	private double width;
	private double height;
	private Color color;
	private double speed;
	private double vx;
	private double vy;



	/**
		Construtor da classe Ball. Observe que quem invoca o construtor desta classe define a velocidade da bola
		(em pixels por millisegundo), mas não define a direção deste movimento. A direção do movimento é determinada
		aleatoriamente pelo construtor.

		@param cx coordenada x da posição inicial da bola (centro do retangulo que a representa).
		@param cy coordenada y da posição inicial da bola (centro do retangulo que a representa).
		@param width largura do retangulo que representa a bola.
		@param height altura do retangulo que representa a bola.
		@param color cor da bola.
		@param speed velocidade da bola (em pixels por millisegundo).
	*/

	public Ball(double cx, double cy, double width, double height, Color color, double speed){
		this.cx = cx;
		this.cy = cy;
		this.width = width;
		this.height = height;
	  this.color = color;
		this.speed = speed;

		this.vx = speed/2;
		this.vy = speed/2;

	}


	/**
		Método chamado sempre que a bola precisa ser (re)desenhada.
	*/

	public void draw(){
		GameLib.setColor(color);
		GameLib.fillRect(cx, cy, width, height);
	}

	/**
		Método chamado quando o estado (posição) da bola precisa ser atualizado.

		@param delta quantidade de millisegundos que se passou entre o ciclo anterior de atualização do jogo e o atual.
	*/

	public void update(long delta){
		cx = cx + vx * delta;
		cy = cy + vy * delta;
	}

	/**
		Método chamado quando detecta-se uma colisão da bola com um jogador.

		@param playerId uma string cujo conteúdo identifica um dos jogadores.
	*/

	public void onPlayerCollision(String playerId){
		vx = -vx;
	}

	/**
		Método chamado quando detecta-se uma colisão da bola com uma parede.

		@param wallId uma string cujo conteúdo identifica uma das paredes da quadra.
	*/

	public void onWallCollision(String wallId){
		if(wallId == "Left" || wallId == "Right") vx = -vx;
		else vy = -vy;
	}

	/**
		Método que verifica se houve colisão da bola com uma parede.

		@param wall referência para uma instância de Wall contra a qual será verificada a ocorrência de colisão da bola.
		@return um valor booleano que indica a ocorrência (true) ou não (false) de colisão.
	*/

	public boolean checkCollision(Wall wall){
		double h_distance = wall.getWidth()/2 + width/2;
		double cxback = wall.getCx() - h_distance;
		double cxfront = wall.getCx() + h_distance;

		double v_distance = wall.getHeight()/2 + height/2;
		double cytop = wall.getCy() + v_distance;
		double cybottom = wall.getCy() - v_distance;

		if((cxback <= cx && cx <= cxfront) && (cytop >= cy && cy >= cybottom))	return true;
		else return false;
	}

	/**
		Método que verifica se houve colisão da bola com um jogador.

		@param player referência para uma instância de Player contra o qual será verificada a ocorrência de colisão da bola.
		@return um valor booleano que indica a ocorrência (true) ou não (false) de colisão.
	*/

	public boolean checkCollision(Player player){
		double h_distance = player.getWidth()/2 + width/2;
		double cxback = player.getCx() - h_distance;
		double cxfront = player.getCx() + h_distance;

		double v_distance = player.getHeight()/2 + height/2;
		double cytop = player.getCy() + v_distance;
		double cybottom = player.getCy() - v_distance;

		if((cxback <= cx && cx <= cxfront) && (cytop >= cy && cy >= cybottom))	return true;
		else return false;
	}

	/**
		Método que devolve a coordenada x do centro do retângulo que representa a bola.
		@return o valor double da coordenada x.
	*/

	public double getCx(){
		return cx;
	}

	/**
		Método que devolve a coordenada y do centro do retângulo que representa a bola.
		@return o valor double da coordenada y.
	*/

	public double getCy(){
		return cy;
	}

	/**
		Método que devolve a velocidade da bola.
		@return o valor double da velocidade.

	*/

	public double getSpeed(){
		return speed;
	}

}
